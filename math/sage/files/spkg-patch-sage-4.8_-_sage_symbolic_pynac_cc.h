--- sage-4.8/sage/symbolic/pynac_cc.h.orig	2010-06-28 16:37:01.000000000 +0000
+++ sage-4.8/sage/symbolic/pynac_cc.h	2012-01-21 22:48:22.000000000 +0000
@@ -1,37 +1,21 @@
-#include <math.h>
+#include <cmath>
 
 inline long double sage_logl(long double x) 
 {
-#if defined(__CYGWIN__)
   return log(x);
-#else
-  return logl(x);
-#endif 
 }
 
 inline long double sage_sqrtl(long double x) 
 {
-#if defined(__CYGWIN__)
   return sqrt(x);
-#else
-  return sqrtl(x);
-#endif 
 } 
 
 inline long double sage_tgammal(long double x) 
 {
-#if defined(__CYGWIN__)
   return tgamma(x);
-#else
-  return tgammal(x);
-#endif 
 }
 
 inline long double sage_lgammal(long double x)
 {
-#if defined(__CYGWIN__)
   return lgamma(x);
-#else
-  return lgammal(x);
-#endif 
 }
