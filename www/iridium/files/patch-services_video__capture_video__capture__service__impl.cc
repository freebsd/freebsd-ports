--- services/video_capture/video_capture_service_impl.cc.orig	2024-12-22 12:24:29 UTC
+++ services/video_capture/video_capture_service_impl.cc
@@ -43,7 +43,7 @@
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "media/capture/capture_switches.h"
 #include "media/capture/video/video_capture_gpu_channel_host.h"
 #include "services/viz/public/cpp/gpu/context_provider_command_buffer.h"
@@ -112,7 +112,7 @@ class VideoCaptureServiceImpl::GpuDependenciesContext 
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // Intended usage of this class is to create viz::Gpu in utility process and
 // connect to viz::GpuClient of browser process, which will call to Gpu service.
 // Also, this class holds the viz::ContextProvider to listen and monitor Gpu
@@ -334,7 +334,7 @@ void VideoCaptureServiceImpl::LazyInitializeGpuDepende
     gpu_dependencies_context_ = std::make_unique<GpuDependenciesContext>();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   {
 #else
@@ -468,7 +468,7 @@ void VideoCaptureServiceImpl::OnGpuInfoUpdate(const CH
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 void VideoCaptureServiceImpl::SetVizGpu(std::unique_ptr<viz::Gpu> viz_gpu) {
   viz_gpu_ = std::move(viz_gpu);
 }
