--- extensions/transformiix/source/base/Double.cpp.orig	Wed May 21 04:42:05 2003
+++ extensions/transformiix/source/base/Double.cpp	Wed May 21 04:42:24 2003
@@ -51,7 +51,7 @@
 //A trick to handle IEEE floating point exceptions on FreeBSD - E.D.
 #ifdef __FreeBSD__
 #include <ieeefp.h>
-#ifdef __alpha__
+#if defined(__alpha__) || defined(__sparc64__)
 fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP;
 #else
 fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP|FP_X_DNML;
