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
+  string size = fontSize->currentText().ascii();
+  string colormode = colorMode->currentText().ascii();
+  string hSize = horizSize->text().ascii();
+  string vSize = vertSize->text().ascii();
 
   gnuInt->setTermPBMFontSize(size);
   gnuInt->setTermPBMColormode(colormode);
