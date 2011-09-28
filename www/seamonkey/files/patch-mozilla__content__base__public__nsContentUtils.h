--- mozilla/content/base/public/nsContentUtils.h.orig	2011-07-07 10:44:49.000000000 +0200
+++ mozilla/content/base/public/nsContentUtils.h	2011-07-07 10:46:12.000000000 +0200
@@ -54,7 +54,7 @@
 //A trick to handle IEEE floating point exceptions on FreeBSD - E.D.
 #ifdef __FreeBSD__
 #include <ieeefp.h>
-#ifdef __alpha__
+#if !defined(__amd64__) && !defined(__i386__)
 static fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP;
 #else
 static fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP|FP_X_DNML;
