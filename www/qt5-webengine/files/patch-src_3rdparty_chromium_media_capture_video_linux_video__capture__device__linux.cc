--- src/3rdparty/chromium/media/capture/video/linux/video_capture_device_linux.cc.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/video_capture_device_linux.cc
@@ -17,7 +17,9 @@
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
+#if !defined(OS_BSD)
 #include <linux/version.h>
+#endif  // defined(OS_BSD)
 #endif
 
 namespace media {
@@ -144,12 +146,8 @@ int VideoCaptureDeviceLinux::TranslatePo
     case media::PowerLineFrequency::FREQUENCY_60HZ:
       return V4L2_CID_POWER_LINE_FREQUENCY_60HZ;
     default:
-#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,2,0)
       // If we have no idea of the frequency, at least try and set it to AUTO.
       return V4L2_CID_POWER_LINE_FREQUENCY_AUTO;
-#else
-      return V4L2_CID_POWER_LINE_FREQUENCY_60HZ;
-#endif
   }
 }
 
