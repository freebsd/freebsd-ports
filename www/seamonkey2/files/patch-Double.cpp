--- extensions/transformiix/source/base/Double.cpp.orig	Thu Jan 30 00:26:46 2003
+++ extensions/transformiix/source/base/Double.cpp	Tue Jun 24 23:30:10 2003
@@ -51,10 +51,10 @@
 //A trick to handle IEEE floating point exceptions on FreeBSD - E.D.
 #ifdef __FreeBSD__
 #include <ieeefp.h>
-#ifdef __alpha__
-fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP;
-#else
+#if defined(__i386__)
 fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP|FP_X_DNML;
+#else
+fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP;
 #endif
 fp_except_t oldmask = fpsetmask(~allmask);
 #endif
