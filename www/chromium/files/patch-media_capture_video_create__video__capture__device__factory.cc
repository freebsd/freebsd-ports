--- media/capture/video/create_video_capture_device_factory.cc.orig	2021-07-19 18:45:18 UTC
+++ media/capture/video/create_video_capture_device_factory.cc
@@ -11,7 +11,7 @@
 #include "media/capture/video/fake_video_capture_device_factory.h"
 #include "media/capture/video/file_video_capture_device_factory.h"
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "media/capture/video/linux/video_capture_device_factory_linux.h"
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
 #include "media/capture/video/chromeos/public/cros_features.h"
@@ -58,7 +58,7 @@ CreateFakeVideoCaptureDeviceFactory() {
 std::unique_ptr<VideoCaptureDeviceFactory>
 CreatePlatformSpecificVideoCaptureDeviceFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return std::make_unique<VideoCaptureDeviceFactoryLinux>(ui_task_runner);
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   return std::make_unique<VideoCaptureDeviceFactoryChromeOS>(ui_task_runner);
