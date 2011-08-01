--- mozilla/content/xslt/public/txDouble.h.orig	2009-08-25 01:35:47.000000000 +0200
+++ mozilla/content/xslt/public/txDouble.h	2009-08-25 01:37:41.000000000 +0200
@@ -43,11 +43,16 @@
 //A trick to handle IEEE floating point exceptions on FreeBSD - E.D.
 #ifdef __FreeBSD__
 #include <ieeefp.h>
-#ifdef __alpha__
-static fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP;
-#else
-static fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP|FP_X_DNML;
+#if !defined(FP_X_DNML)
+#define FP_X_DNML 0
+#endif
+#if !defined(FP_X_STK)
+#define FP_X_STK 0
+#endif
+#if !defined(FP_X_IOV)
+#define FP_X_IOV 0
 #endif
+static fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP|FP_X_DNML|FP_X_STK|FP_X_IOV;
 static fp_except_t oldmask = fpsetmask(~allmask);
 #endif
 
