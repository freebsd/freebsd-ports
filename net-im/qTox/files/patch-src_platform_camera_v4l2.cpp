--- src/platform/camera/v4l2.cpp.orig	2015-06-15 03:25:21 UTC
+++ src/platform/camera/v4l2.cpp
@@ -26,6 +26,7 @@
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <linux/videodev2.h>
+#include <errno.h>
 
 /**
  * Most of this file is adapted from libavdevice's v4l2.c,
