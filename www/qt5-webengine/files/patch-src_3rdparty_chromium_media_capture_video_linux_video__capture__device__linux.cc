--- src/3rdparty/chromium/media/capture/video/linux/video_capture_device_linux.cc.orig	2020-04-08 09:41:36 UTC
+++ src/3rdparty/chromium/media/capture/video/linux/video_capture_device_linux.cc
@@ -17,8 +17,10 @@
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
+#if !defined(OS_FREEBSD)
 #include <linux/version.h>
 #endif
+#endif
 
 namespace media {
 
@@ -31,12 +33,12 @@ int TranslatePowerLineFrequencyToV4L2(PowerLineFrequen
     case PowerLineFrequency::FREQUENCY_60HZ:
       return V4L2_CID_POWER_LINE_FREQUENCY_60HZ;
     default:
-#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,2,0)
+//#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,2,0)
       // If we have no idea of the frequency, at least try and set it to AUTO.
       return V4L2_CID_POWER_LINE_FREQUENCY_AUTO;
-#else
-      return V4L2_CID_POWER_LINE_FREQUENCY_60HZ;
-#endif
+//#else
+//      return V4L2_CID_POWER_LINE_FREQUENCY_60HZ;
+//#endif
   }
 }
 
