diff -u pbmOp.cpp.orig pbmOp.cpp
--- pbmOp.cpp.orig	Tue May 19 05:13:52 1998
+++ pbmOp.cpp	Thu Oct 30 21:42:04 2003
@@ -74,10 +74,10 @@
 void pbmOp::setTerm()
 {
   // get options
-  string size = fontSize->currentText();
-  string colormode = colorMode->currentText();
-  string hSize = horizSize->text();
-  string vSize = vertSize->text();
+  string size = string(fontSize->currentText());
+  string colormode = string(colorMode->currentText());
+  string hSize = string(horizSize->text());
+  string vSize = string(vertSize->text());
 
   gnuInt->setTermPBMFontSize(size);
   gnuInt->setTermPBMColormode(colormode);
