--- gview_v4l2core/v4l2_core.c.orig	2024-11-02 13:15:33 UTC
+++ gview_v4l2core/v4l2_core.c
@@ -96,9 +96,9 @@ int xioctl(int fd, int IOCTL_X, void *arg) {
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
