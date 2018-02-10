--- src/conky.cc.orig	2018-02-07 14:16:39 UTC
+++ src/conky.cc
@@ -132,7 +132,7 @@
 #include <microhttpd.h>
 #endif
 
-#if defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD_kernel__) && (__FreeBSD_kernel__ + 0)
 #include <bsd/bsd.h>
 #endif
 
