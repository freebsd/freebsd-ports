--- multiFunc.cpp.orig	Sat Mar 21 04:26:33 1998
+++ multiFunc.cpp	Thu Oct 30 21:42:04 2003
@@ -76,7 +76,7 @@
   if (multiFuncList->count() > 0)
   {
     // get current function
-    function = multiFuncList->currentText();
+    function = multiFuncList->currentText().ascii();
     
     // get style option
     string style = gnuInt->getMultiFuncStyleOption(function);
@@ -135,7 +135,7 @@
 void multiFunc::insertNewFunction()
 {
   // get function in edit box
-  string function = functionEdit->text();
+  string function = functionEdit->text().ascii();
 
   // insert function in list
   multiFuncList->insertItem(function.c_str(),0);
@@ -158,17 +158,17 @@
   if (multiFuncList->count() > 0)
   {
     // get function
-    string function = multiFuncList->currentText();
+    string function = multiFuncList->currentText().ascii();
 
     // get options
-    string style = funcStyleList->currentText();
+    string style = funcStyleList->currentText().ascii();
     
     // set options
     gnuInt->setMultiFuncStyleOption(function,style);
 
 
     // set title
-    string title = legendTitleEdit->text();
+    string title = legendTitleEdit->text().ascii();
     gnuInt->setMultiFuncLegendTitle(function, title);
 
     if (legendTitleDefaultButton->isChecked() == TRUE)
@@ -194,7 +194,7 @@
     multiFuncList->setCurrentItem(0);
     
     // get current function in combo box
-    string function = multiFuncList->currentText();
+    string function = multiFuncList->currentText().ascii();
     
     int currentItem = multiFuncList->currentItem();
     
@@ -211,7 +211,7 @@
       multiFuncList->setCurrentItem(0);
       
       // get function that is now current in combo box
-      function = multiFuncList->currentText();
+      function = multiFuncList->currentText().ascii();
 
       // set edit box to current function
       functionEdit->setText(function.c_str());
