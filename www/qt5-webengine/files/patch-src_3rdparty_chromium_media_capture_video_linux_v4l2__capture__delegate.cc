--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.cc.orig	2017-01-26 00:49:15 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.cc
@@ -4,7 +4,9 @@
 
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
+#if !defined(OS_BSD)
 #include <linux/version.h>
+#endif
 #include <poll.h>
 #include <sys/fcntl.h>
 #include <sys/ioctl.h>
@@ -20,10 +22,10 @@
 #include "media/capture/video/blob_utils.h"
 #include "media/capture/video/linux/video_capture_device_linux.h"
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
+// #if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
 // 16 bit depth, Realsense F200.
 #define V4L2_PIX_FMT_Z16 v4l2_fourcc('Z', '1', '6', ' ')
-#endif
+// #endif
 
 // TODO(aleksandar.stojiljkovic): Wrap this with kernel version check once the
 // format is introduced to kernel.
