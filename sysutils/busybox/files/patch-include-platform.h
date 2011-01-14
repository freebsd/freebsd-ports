--- include/platform.h.orig	2011-01-14 10:33:51.000000000 +0100
+++ include/platform.h	2011-01-14 10:37:09.000000000 +0100
@@ -224,12 +224,14 @@
 typedef long                intmax_t;
 typedef unsigned long       uintmax_t;
 #else
+#if !defined(__FreeBSD__)
 __extension__
 typedef long long           intmax_t;
 __extension__
 typedef unsigned long long  uintmax_t;
 #endif
 #endif
+#endif
 
 /* Size-saving "small" ints (arch-dependent) */
 #if defined(i386) || defined(__x86_64__) || defined(__mips__) || defined(__cris__)
