--- src/libs/media.c.orig	2026-08-03 07:20:54 UTC
+++ src/libs/media.c
@@ -26,7 +26,9 @@
 #include <unistd.h>
 #include <fcntl.h>
 
+#if defined(__linux__)
 #include <sys/sysmacros.h>
+#endif
 
 #include <linux/videodev2.h>
 #include <linux/media.h>
