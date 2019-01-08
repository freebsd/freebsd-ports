--- media/capture/video/create_video_capture_device_factory.cc.orig	2018-12-12 22:56:08.000000000 +0100
+++ media/capture/video/create_video_capture_device_factory.cc	2018-12-30 23:29:59.281943000 +0100
@@ -10,7 +10,7 @@
 #include "media/capture/video/fake_video_capture_device_factory.h"
 #include "media/capture/video/file_video_capture_device_factory.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "media/capture/video/linux/video_capture_device_factory_linux.h"
 #elif defined(OS_CHROMEOS)
 #include "media/capture/video/chromeos/public/cros_features.h"
@@ -33,7 +33,7 @@
 std::unique_ptr<VideoCaptureDeviceFactory>
 CreatePlatformSpecificVideoCaptureDeviceFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return std::make_unique<VideoCaptureDeviceFactoryLinux>(ui_task_runner);
 #elif defined(OS_CHROMEOS)
   // On Chrome OS we have to support two use cases:
