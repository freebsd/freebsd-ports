--- content/browser/renderer_host/media/service_video_capture_device_launcher.cc.orig	2025-07-02 06:08:04 UTC
+++ content/browser/renderer_host/media/service_video_capture_device_launcher.cc
@@ -29,7 +29,7 @@
 #include "media/base/media_switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/browser/gpu/gpu_data_manager_impl.h"
 #endif
 
@@ -188,7 +188,7 @@ void ServiceVideoCaptureDeviceLauncher::LaunchDeviceAs
   }
 #else
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // On Linux, additionally check whether the NV12 GPU memory buffer is
     // supported.
     if (GpuDataManagerImpl::GetInstance()->IsGpuMemoryBufferNV12Supported())
