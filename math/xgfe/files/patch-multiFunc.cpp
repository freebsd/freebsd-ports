diff -u multiFunc.cpp.orig multiFunc.cpp
--- multiFunc.cpp.orig	Sat Mar 21 04:26:33 1998
+++ multiFunc.cpp	Thu Oct 30 21:42:04 2003
@@ -135,7 +135,7 @@
 void multiFunc::insertNewFunction()
 {
   // get function in edit box
-  string function = functionEdit->text();
+  string function = string(functionEdit->text());
 
   // insert function in list
   multiFuncList->insertItem(function.c_str(),0);
@@ -158,17 +158,17 @@
   if (multiFuncList->count() > 0)
   {
     // get function
-    string function = multiFuncList->currentText();
+    string function = string(multiFuncList->currentText());
 
     // get options
-    string style = funcStyleList->currentText();
+    string style = string(funcStyleList->currentText());
     
     // set options
     gnuInt->setMultiFuncStyleOption(function,style);
 
 
     // set title
-    string title = legendTitleEdit->text();
+    string title = string(legendTitleEdit->text());
     gnuInt->setMultiFuncLegendTitle(function, title);
 
     if (legendTitleDefaultButton->isChecked() == TRUE)
@@ -194,7 +194,7 @@
     multiFuncList->setCurrentItem(0);
     
     // get current function in combo box
-    string function = multiFuncList->currentText();
+    string function = string(multiFuncList->currentText());
     
     int currentItem = multiFuncList->currentItem();
     
