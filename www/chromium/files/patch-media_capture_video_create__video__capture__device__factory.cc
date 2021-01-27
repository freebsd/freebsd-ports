--- media/capture/video/create_video_capture_device_factory.cc.orig	2021-01-18 21:29:00 UTC
+++ media/capture/video/create_video_capture_device_factory.cc
@@ -11,7 +11,7 @@
 #include "media/capture/video/fake_video_capture_device_factory.h"
 #include "media/capture/video/file_video_capture_device_factory.h"
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_LACROS) || defined(OS_BSD)
 #include "media/capture/video/linux/video_capture_device_factory_linux.h"
 #elif BUILDFLAG(IS_ASH)
 #include "media/capture/video/chromeos/camera_app_device_bridge_impl.h"
@@ -83,7 +83,7 @@ CreateChromeOSVideoCaptureDeviceFactory(
 std::unique_ptr<VideoCaptureDeviceFactory>
 CreatePlatformSpecificVideoCaptureDeviceFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
-#if defined(OS_LINUX) || BUILDFLAG(IS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_LACROS) || defined(OS_BSD)
   return std::make_unique<VideoCaptureDeviceFactoryLinux>(ui_task_runner);
 #elif BUILDFLAG(IS_ASH)
   return CreateChromeOSVideoCaptureDeviceFactory(ui_task_runner, {});
