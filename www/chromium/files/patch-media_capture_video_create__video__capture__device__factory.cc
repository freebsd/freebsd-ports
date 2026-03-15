--- media/capture/video/create_video_capture_device_factory.cc.orig	2026-03-13 06:02:14 UTC
+++ media/capture/video/create_video_capture_device_factory.cc
@@ -14,7 +14,7 @@
 #include "media/capture/video/fake_video_capture_device_factory.h"
 #include "media/capture/video/file_video_capture_device_factory.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "media/capture/video/linux/video_capture_device_factory_linux.h"
 #elif BUILDFLAG(IS_CHROMEOS)
 #include "media/capture/video/chromeos/public/cros_features.h"
@@ -58,7 +58,7 @@ std::unique_ptr<VideoCaptureDeviceFactory>
 CreatePlatformSpecificVideoCaptureDeviceFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner,
     gpu::GpuDriverBugWorkarounds* gpu_workarounds) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<VideoCaptureDeviceFactoryLinux>(ui_task_runner);
 #elif BUILDFLAG(IS_CHROMEOS)
   if (base::SysInfo::IsRunningOnChromeOS())
