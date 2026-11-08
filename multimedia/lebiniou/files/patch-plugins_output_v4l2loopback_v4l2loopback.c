--- plugins/output/v4l2loopback/v4l2loopback.c.orig	2024-08-31 21:52:17 UTC
+++ plugins/output/v4l2loopback/v4l2loopback.c
@@ -24,6 +24,9 @@
 #if HAVE_SYS_VIDEOIO_H
 #include <sys/videoio.h>
 #endif
+#if defined(__FreeBSD__)
+typedef uint32_t __u32;
+#endif
 #include "pthread_utils.h"
 
 
