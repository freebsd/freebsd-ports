diff -u rotation.cpp.orig rotation.cpp
--- rotation.cpp.orig	Thu Jul 23 04:31:04 1998
+++ rotation.cpp	Thu Oct 30 21:42:04 2003
@@ -62,8 +62,8 @@
 
 void rotation::doOK()
 {  
-  string scale = plotScalingEdit->text();
-  string zscale = zAxisScalingEdit->text();
+  string scale = plotScalingEdit->text().ascii();
+  string zscale = zAxisScalingEdit->text().ascii();
 
   gnuInt->setRotationXAxis(xAxisRotation);
   gnuInt->setRotationZAxis(zAxisRotation);
