--- media/capture/video/video_capture_buffer_tracker_factory_impl.cc.orig	2023-12-23 12:33:28 UTC
+++ media/capture/video/video_capture_buffer_tracker_factory_impl.cc
@@ -14,7 +14,7 @@
 #include "media/capture/video/chromeos/gpu_memory_buffer_tracker_cros.h"
 #elif BUILDFLAG(IS_APPLE)
 #include "media/capture/video/apple/gpu_memory_buffer_tracker_apple.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "media/capture/video/linux/v4l2_gpu_memory_buffer_tracker.h"
 #elif BUILDFLAG(IS_WIN)
 #include "media/capture/video/win/gpu_memory_buffer_tracker_win.h"
@@ -42,7 +42,7 @@ VideoCaptureBufferTrackerFactoryImpl::CreateTracker(
       return std::make_unique<GpuMemoryBufferTrackerCros>();
 #elif BUILDFLAG(IS_APPLE)
       return std::make_unique<GpuMemoryBufferTrackerApple>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return std::make_unique<V4L2GpuMemoryBufferTracker>();
 #elif BUILDFLAG(IS_WIN)
       if (!dxgi_device_manager_) {
