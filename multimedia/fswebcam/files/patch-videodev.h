--- videodev.h.orig	2020-07-25 18:25:51 UTC
+++ videodev.h
@@ -12,8 +12,9 @@
 #ifndef __LINUX_VIDEODEV_H
 #define __LINUX_VIDEODEV_H
 
+#include <infiniband/types.h>
 #include <linux/types.h>
-#include <linux/ioctl.h>
+/* #include <linux/ioctl.h> */
 #include <linux/videodev2.h>
 
 
