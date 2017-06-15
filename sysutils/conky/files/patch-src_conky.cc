--- src/conky.cc.orig	2016-10-04 07:49:19 UTC
+++ src/conky.cc
@@ -129,7 +129,7 @@
 #include <microhttpd.h>
 #endif
 
-#if defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD_kernel__) && (__FreeBSD_kernel__ + 0)
 #include <bsd/bsd.h>
 #endif
 
