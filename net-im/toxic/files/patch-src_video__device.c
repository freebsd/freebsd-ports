--- src/video_device.c.orig	2017-11-17 22:44:56 UTC
+++ src/video_device.c
@@ -37,7 +37,7 @@
 #include <sys/stat.h>
 #include <sys/mman.h>
 #include <fcntl.h>
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <linux/videodev2.h>
 #else
 #include <sys/videoio.h>
