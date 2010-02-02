--- src/modules/bugs/matrix/matrix.cc.orig	2009-12-26 15:49:36.000000000 -0500
+++ src/modules/bugs/matrix/matrix.cc	2009-12-26 15:48:07.000000000 -0500
@@ -41,6 +41,7 @@
   }
 
   if (w[0] <= 0) {
+    delete [] w;
     throw runtime_error("Non positive definite matrix in call to logdet");
   }
 
