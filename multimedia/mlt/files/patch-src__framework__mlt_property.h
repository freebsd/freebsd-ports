--- ./src/framework/mlt_property.h.orig	2012-06-01 22:51:32.000000000 +0200
+++ ./src/framework/mlt_property.h	2012-06-12 03:54:31.992557693 +0200
@@ -30,7 +30,7 @@
 #include <sys/param.h>
 #endif
 
-#if defined(__GLIBC__) || defined(__DARWIN__) || (__FreeBSD_version >= 1000002)
+#if defined(__GLIBC__) || defined(__DARWIN__) || (__FreeBSD_version >= 900506)
 #include <xlocale.h>
 #else
 typedef void* locale_t;
