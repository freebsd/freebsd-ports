--- content/xslt/public/txDouble.h.orig	Fri Oct 13 00:00:29 2006
+++ content/xslt/public/txDouble.h	Fri Oct 13 00:00:53 2006
@@ -41,7 +41,7 @@
 #define __txdouble_h__
 
 //A trick to handle IEEE floating point exceptions on FreeBSD - E.D.
-#ifdef __FreeBSD__
+/* #ifdef __FreeBSD__
 #include <ieeefp.h>
 #ifdef __alpha__
 fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP;
@@ -50,7 +50,7 @@
 #endif
 fp_except_t oldmask = fpsetmask(~allmask);
 #endif
-
+*/
 /**
  * Macros to workaround math-bugs bugs in various platforms
  */
