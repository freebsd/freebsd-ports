--- ./media/video/capture/video_capture_device_factory.cc.orig	2014-08-20 21:03:15.000000000 +0200
+++ ./media/video/capture/video_capture_device_factory.cc	2014-08-22 22:39:36.000000000 +0200
@@ -11,7 +11,7 @@
 
 #if defined(OS_MACOSX)
 #include "media/video/capture/mac/video_capture_device_factory_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_OPENBSD)
 #include "media/video/capture/linux/video_capture_device_factory_linux.h"
 #elif defined(OS_ANDROID)
 #include "media/video/capture/android/video_capture_device_factory_android.h"
@@ -41,7 +41,7 @@
 #if defined(OS_MACOSX)
     return scoped_ptr<VideoCaptureDeviceFactory>(new
         VideoCaptureDeviceFactoryMac(ui_task_runner));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_OPENBSD)
     return scoped_ptr<VideoCaptureDeviceFactory>(new
         VideoCaptureDeviceFactoryLinux(ui_task_runner));
 #elif defined(OS_ANDROID)
