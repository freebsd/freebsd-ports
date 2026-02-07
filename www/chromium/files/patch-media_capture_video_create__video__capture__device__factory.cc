--- media/capture/video/create_video_capture_device_factory.cc.orig	2025-08-07 06:57:29 UTC
+++ media/capture/video/create_video_capture_device_factory.cc
@@ -13,7 +13,7 @@
 #include "media/capture/video/fake_video_capture_device_factory.h"
 #include "media/capture/video/file_video_capture_device_factory.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "media/capture/video/linux/video_capture_device_factory_linux.h"
 #elif BUILDFLAG(IS_CHROMEOS)
 #include "media/capture/video/chromeos/public/cros_features.h"
@@ -56,7 +56,7 @@ CreateFakeVideoCaptureDeviceFactory() {
 std::unique_ptr<VideoCaptureDeviceFactory>
 CreatePlatformSpecificVideoCaptureDeviceFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<VideoCaptureDeviceFactoryLinux>(ui_task_runner);
 #elif BUILDFLAG(IS_CHROMEOS)
   if (base::SysInfo::IsRunningOnChromeOS())
