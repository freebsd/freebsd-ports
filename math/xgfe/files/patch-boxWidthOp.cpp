diff -u boxWidthOp.cpp.orig boxWidthOp.cpp
--- boxWidthOp.cpp.orig	Sat May 30 23:51:13 1998
+++ boxWidthOp.cpp	Thu Oct 30 21:42:04 2003
@@ -57,7 +57,7 @@
 
 void boxWidthOp::setBoxWidth()
 {
-  string width = boxWidthEdit->text();
+  string width = boxWidthEdit->text().ascii();
   
   gnuInt->setBoxWidth(width);
 
