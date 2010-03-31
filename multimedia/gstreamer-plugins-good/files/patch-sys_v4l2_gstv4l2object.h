--- sys/v4l2/gstv4l2object.h.orig	2010-02-11 17:52:41.000000000 +0100
+++ sys/v4l2/gstv4l2object.h	2010-02-11 17:57:50.000000000 +0100
@@ -38,13 +38,15 @@
  */
 #include <sys/ioctl.h>
 #include <sys/types.h>
-#ifndef __sun
+#ifdef __sun
+#include <sys/videodev2.h>
+#elif defined(__FreeBSD__)
+#include <linux/videodev2.h>
+#else /* linux */
 #include <linux/types.h>
 #define _LINUX_TIME_H
 #define __user
 #include <linux/videodev2.h>
-#else
-#include <sys/videodev2.h>
 #endif
 
 #include <gst/gst.h>
