--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.cc.orig	2019-03-01 17:04:22 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.cc
@@ -4,8 +4,10 @@
 
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
+#if !defined(OS_BSD)
 #include <linux/version.h>
 #include <linux/videodev2.h>
+#endif
 #include <poll.h>
 #include <sys/fcntl.h>
 #include <sys/ioctl.h>
@@ -13,7 +15,7 @@
 
 #include <utility>
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 #include <linux/version.h>
 #endif
 
@@ -28,10 +30,10 @@
 
 using media::mojom::MeteringMode;
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
+// #if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
 // 16 bit depth, Realsense F200.
 #define V4L2_PIX_FMT_Z16 v4l2_fourcc('Z', '1', '6', ' ')
-#endif
+// #endif
 
 // TODO(aleksandar.stojiljkovic): Wrap this with kernel version check once the
 // format is introduced to kernel.
@@ -342,9 +344,9 @@ void V4L2CaptureDelegate::AllocateAndStart(
   // operation (|errno| == EINVAL in this case) or plain failure.
   if ((power_line_frequency_ == V4L2_CID_POWER_LINE_FREQUENCY_50HZ)
       || (power_line_frequency_ == V4L2_CID_POWER_LINE_FREQUENCY_60HZ)
-#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,2,0)
+//#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,2,0)
       || (power_line_frequency_ == V4L2_CID_POWER_LINE_FREQUENCY_AUTO)
-#endif
+//#endif
     ) {
     struct v4l2_control control = {};
     control.id = V4L2_CID_POWER_LINE_FREQUENCY;
