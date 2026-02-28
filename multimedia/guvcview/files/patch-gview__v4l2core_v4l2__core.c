--- gview_v4l2core/v4l2_core.c.orig	2025-11-09 18:30:53 UTC
+++ gview_v4l2core/v4l2_core.c
@@ -97,9 +97,9 @@ int xioctl(int fd, int IOCTL_X, void *arg) {
   int ret = 0;
   int tries = IOCTL_RETRY;
   do {
-    if (!disable_libv4l2)
+/*    if (!disable_libv4l2)
       ret = v4l2_ioctl(fd, IOCTL_X, arg);
-    else
+    else*/
       ret = ioctl(fd, IOCTL_X, arg);
   } while (ret && tries-- &&
            ((errno == EINTR) || (errno == EAGAIN) || (errno == ETIMEDOUT)));
