diff -u isoLinesOp.cpp.orig isoLinesOp.cpp
--- isoLinesOp.cpp.orig	Wed Sep 30 04:29:34 1998
+++ isoLinesOp.cpp	Thu Oct 30 21:42:04 2003
@@ -63,8 +63,8 @@
 
 void isoLinesOp::setIsolinesOp()
 {
-  string isoU = isoUEdit->text();
-  string isoV = isoVEdit->text();
+  string isoU = isoUEdit->text().ascii();
+  string isoV = isoVEdit->text().ascii();
   
   gnuInt->setIsolineU(isoU);
   gnuInt->setIsolineV(isoV);
