--- content/xslt/public/txDouble.h.orig	2009-08-16 21:46:27.000000000 +0200
+++ content/xslt/public/txDouble.h	2009-08-16 21:49:53.000000000 +0200
@@ -43,7 +43,7 @@
 //A trick to handle IEEE floating point exceptions on FreeBSD - E.D.
 #ifdef __FreeBSD__
 #include <ieeefp.h>
-#ifdef __alpha__
+#if defined (__alpha__) || defined (__powerpc__) || defined (__sparc__)
 static fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP;
 #else
 static fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP|FP_X_DNML;
