diff -u latexEmtexOp.cpp.orig latexEmtexOp.cpp
--- latexEmtexOp.cpp.orig	Tue May 19 03:20:25 1998
+++ latexEmtexOp.cpp	Thu Oct 30 21:42:04 2003
@@ -71,9 +71,9 @@
 void latexEmtexOp::setTerm()
 {
   // set options
-  string font = FontList->currentText();
-  string size = FontSizeList->currentText();
-  string otherSize = FontSizeOther->text();
+  string font = string(FontList->currentText());
+  string size = string(FontSizeList->currentText());
+  string otherSize = string(FontSizeOther->text());
 
   gnuInt->setTermLateXEmtexFont(font);
     
