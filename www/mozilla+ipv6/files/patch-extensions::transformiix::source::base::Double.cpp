
$FreeBSD$

--- extensions/transformiix/source/base/Double.cpp.orig	Sat Nov 24 00:36:13 2001
+++ extensions/transformiix/source/base/Double.cpp	Tue Dec 25 15:19:42 2001
@@ -41,7 +41,7 @@
 #endif
 //A trick to handle IEEE floating point exceptions on FreeBSD - E.D.
 #ifdef __FreeBSD__
-#include <floatingpoint.h>
+#include <ieeefp.h>
 #endif
 #ifndef TX_EXE
 #include "prdtoa.h"
@@ -56,7 +56,11 @@
 
 //A trick to handle IEEE floating point exceptions on FreeBSD - E.D.
 #ifdef __FreeBSD__
+#ifdef __alpha__
+fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP;
+#else
 fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP|FP_X_DNML;
+#endif
 fp_except_t oldmask = fpsetmask(~allmask);
 #endif
 
