--- videodev2.h.orig	2020-07-25 18:25:51 UTC
+++ videodev2.h
@@ -59,7 +59,8 @@
 
 #include <sys/time.h>
 
-#include <linux/ioctl.h>
+/* #include <linux/ioctl.h> */
+#include <infiniband/types.h>
 #include <linux/types.h>
 #include <linux/v4l2-common.h>
 #include <linux/v4l2-controls.h>
