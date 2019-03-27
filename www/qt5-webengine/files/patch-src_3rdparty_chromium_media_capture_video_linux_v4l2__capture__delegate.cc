--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.cc
@@ -4,15 +4,17 @@
 
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
+#if !defined(OS_BSD)
 #include <linux/version.h>
 #include <linux/videodev2.h>
+#endif
 #include <poll.h>
 #include <sys/fcntl.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 #include <utility>
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 #include <linux/version.h>
 #endif
 
@@ -27,10 +29,10 @@
 
 using media::mojom::MeteringMode;
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
+// #if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
 // 16 bit depth, Realsense F200.
 #define V4L2_PIX_FMT_Z16 v4l2_fourcc('Z', '1', '6', ' ')
-#endif
+// #endif
 
 // TODO(aleksandar.stojiljkovic): Wrap this with kernel version check once the
 // format is introduced to kernel.
@@ -367,9 +369,9 @@ void V4L2CaptureDelegate::AllocateAndStart(
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
