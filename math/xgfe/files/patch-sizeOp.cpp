diff -u sizeOp.cpp.orig sizeOp.cpp
--- sizeOp.cpp.orig	Wed May 27 02:37:46 1998
+++ sizeOp.cpp	Thu Oct 30 21:42:04 2003
@@ -57,8 +57,8 @@
 
 void sizeOp::setSize()
 {
-  string hSize = hSizeEdit->text();
-  string vSize = vSizeEdit->text();
+  string hSize = string(hSizeEdit->text());
+  string vSize = string(vSizeEdit->text());
 
   gnuInt->setHorizSize(hSize);
   gnuInt->setVertSize(vSize);
