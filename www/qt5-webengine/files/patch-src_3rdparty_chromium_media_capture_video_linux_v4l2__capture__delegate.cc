--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.cc.orig	2017-04-19 19:13:43 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.cc
@@ -20,7 +20,7 @@
 #include "media/capture/video/linux/v4l2_capture_delegate_single_plane.h"
 #include "media/capture/video/linux/video_capture_device_linux.h"
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 #include <linux/version.h>
 #endif
 
@@ -277,9 +277,7 @@ void V4L2CaptureDelegate::AllocateAndSta
   // operation (|errno| == EINVAL in this case) or plain failure.
   if ((power_line_frequency_ == V4L2_CID_POWER_LINE_FREQUENCY_50HZ)
       || (power_line_frequency_ == V4L2_CID_POWER_LINE_FREQUENCY_60HZ)
-#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,2,0)
       || (power_line_frequency_ == V4L2_CID_POWER_LINE_FREQUENCY_AUTO)
-#endif
      ) {
     struct v4l2_control control = {};
     control.id = V4L2_CID_POWER_LINE_FREQUENCY;
