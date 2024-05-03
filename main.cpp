#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
   cout << "MENU" << endl; 
   cout << "a - Add item to cart" << endl; 
   cout << "d - Remove item from cart" << endl; 
   cout << "c - Change item quantity" << endl; 
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl; 
   cout << "q - Quit" << endl;   
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   
   switch(option){ 
      
case 'o':
   cout << "OUTPUT SHOPPING CART" << endl; 
   theCart.PrintTotal(); 
   cout << endl; 
      break; 
case 'i': 
   cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl; 
   theCart.PrintDescriptions(); 
   cout << endl; 
      break; 
case 'a': { 
   cin.ignore(); 
   string itemName; 
   string itemDescription;
   int itemPrice; 
   int itemQuantity; 
   cout << "ADD ITEM TO CART" << endl; 
   cout << "Enter the item name:" << endl; 
   getline(cin, itemName); 
   cout << "Enter the item description:" << endl; 
   getline(cin, itemDescription); 
   cout << "Enter the item price:" << endl; 
   cin >> itemPrice; 
   cin.ignore(); 
   cout << "Enter the item quantity:" << endl; 
   cin >> itemQuantity; 
   cin.ignore(); 
   ItemToPurchase newItem; 
   newItem.SetName(itemName); 
   newItem.SetDescription(itemDescription); 
   newItem.SetPrice(itemPrice); 
   newItem.SetQuantity(itemQuantity); 
   theCart.AddItem(newItem); 
   cout << endl; 
   break; 
}
case'd':{
   cin.ignore(); 
   string itemName; 
   cout << "REMOVE ITEM FROM CART" << endl; 
   cout << "Enter name of item to remove:" << endl; 
   getline(cin, itemName); 
   theCart.RemoveItem(itemName); 
   cout << endl; 
   break; 
} 
case 'c':{
   cin.ignore(); 
   string itemName; 
   int newQuantity; 
   cout << "CHANGE ITEM QUANTITY" << endl; 
   cout << "Enter the item name:" << endl; 
   getline(cin, itemName); 
   cout << "Enter the new quantity:" << endl; 
   cin >> newQuantity; 
   cin.ignore(); 
   ItemToPurchase newItem2; 
   newItem2.SetName(itemName); 
   newItem2.SetQuantity(newQuantity); 
   theCart.ModifyItem(newItem2); 
   cout << endl; 
   break; 
} 
} 
} 

int main() {
   string customerName; 
   string currentDate; 
   char opt; 
   cout << "Enter customer's name:" << endl;
   getline(cin, customerName); 
   cout << "Enter today's date:" << endl; 
   getline(cin, currentDate); 
   cout << endl; 
   
   ShoppingCart cart(customerName, currentDate); 
   
   cout << "Customer name: " << cart.GetCustomerName() << endl; 
   cout << "Today's date: " << cart.GetDate() << endl; 
   cout << endl; 
   
   PrintMenu(); 
   cout << endl; 
   cout << "Choose an option:" << endl; 
   cin >> opt; 
   
   do{
      if(opt != 'a' && opt != 'd' && opt != 'c' && opt != 'i' && opt != 'o' && opt != 'q'){ 
         cout << "Choose an option:" << endl; 
         cin >> opt; 
      }else if (opt == 'q'){
         break; 
   }else{
      ExecuteMenu(opt, cart); 
      PrintMenu(); 
      cout << endl; 
      cout << "Choose an option:" << endl; 
      cin >> opt; 
   }
}while(opt != 'q'); 
 
   return 0;
}
