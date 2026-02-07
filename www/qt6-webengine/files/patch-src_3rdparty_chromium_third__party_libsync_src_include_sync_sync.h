--- src/3rdparty/chromium/third_party/libsync/src/include/sync/sync.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/third_party/libsync/src/include/sync/sync.h
@@ -22,7 +22,9 @@
 #include <sys/cdefs.h>
 #include <stdint.h>
 
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <linux/types.h>
+#endif
 
 __BEGIN_DECLS
 
