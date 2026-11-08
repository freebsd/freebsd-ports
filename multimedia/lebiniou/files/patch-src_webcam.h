--- src/webcam.h.orig	2024-08-31 21:52:17 UTC
+++ src/webcam.h
@@ -27,6 +27,9 @@
 #if HAVE_SYS_VIDEOIO_H
 #include <sys/videoio.h>
 #endif
+#if defined(__FreeBSD__)
+typedef uint32_t __u32;
+#endif
 #include "globals.h"
 
 #ifndef CAPTURE_SET
