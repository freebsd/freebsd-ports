--- barOp.cpp.orig	Thu May  7 07:46:39 1998
+++ barOp.cpp	Thu Oct 30 21:42:04 2003
@@ -59,7 +59,7 @@
 
 void barOp::setBarOption()
 {
-  string barSize = barSizeEdit->text();
+  string barSize = barSizeEdit->text().ascii();
   
   if (barSize != "")
   {
@@ -67,7 +67,7 @@
   }
   else
   {
-    barSize = synList->currentText();
+    barSize = synList->currentText().ascii();
     gnuInt->setBarSizeOption(barSize);
   }
   
