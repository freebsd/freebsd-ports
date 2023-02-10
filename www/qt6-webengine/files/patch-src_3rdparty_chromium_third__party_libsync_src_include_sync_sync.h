--- src/3rdparty/chromium/third_party/libsync/src/include/sync/sync.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/libsync/src/include/sync/sync.h
@@ -22,7 +22,9 @@
 #include <sys/cdefs.h>
 #include <stdint.h>
 
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <linux/types.h>
+#endif
 
 __BEGIN_DECLS
 
