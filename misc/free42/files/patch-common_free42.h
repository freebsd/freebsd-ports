--- common/free42.h.orig	2017-11-20 23:46:32 UTC
+++ common/free42.h
@@ -70,7 +70,7 @@
  * provided by MathLib.
  */
 extern "C" void sincos(double x, double *sinx, double *cosx);
-//#define NO_SINCOS 1
+#define NO_SINCOS 1
 
 #endif
 
