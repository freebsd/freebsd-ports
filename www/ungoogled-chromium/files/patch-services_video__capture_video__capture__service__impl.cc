--- services/video_capture/video_capture_service_impl.cc.orig	2024-02-03 15:42:55 UTC
+++ services/video_capture/video_capture_service_impl.cc
@@ -41,7 +41,7 @@
 #include "services/video_capture/lacros/device_factory_adapter_lacros.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "media/capture/capture_switches.h"
 #include "media/capture/video/video_capture_gpu_channel_host.h"
 #include "services/viz/public/cpp/gpu/context_provider_command_buffer.h"
@@ -108,7 +108,7 @@ class VideoCaptureServiceImpl::GpuDependenciesContext 
       this};
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Intended usage of this class is to create viz::Gpu in utility process and
 // connect to viz::GpuClient of browser process, which will call to Gpu service.
 // Also, this class holds the viz::ContextProvider to listen and monitor Gpu
@@ -299,7 +299,7 @@ void VideoCaptureServiceImpl::LazyInitializeGpuDepende
   if (!gpu_dependencies_context_)
     gpu_dependencies_context_ = std::make_unique<GpuDependenciesContext>();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled()) {
     if (!viz_gpu_context_provider_) {
       viz_gpu_context_provider_ =
@@ -409,7 +409,7 @@ void VideoCaptureServiceImpl::OnGpuInfoUpdate(const CH
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 void VideoCaptureServiceImpl::SetVizGpu(std::unique_ptr<viz::Gpu> viz_gpu) {
   viz_gpu_ = std::move(viz_gpu);
 }
