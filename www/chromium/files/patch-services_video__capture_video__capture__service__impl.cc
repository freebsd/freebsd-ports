--- services/video_capture/video_capture_service_impl.cc.orig	2023-05-31 08:12:17 UTC
+++ services/video_capture/video_capture_service_impl.cc
@@ -43,7 +43,7 @@
 #include "services/video_capture/lacros/device_factory_adapter_lacros.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "media/capture/capture_switches.h"
 #include "services/viz/public/cpp/gpu/context_provider_command_buffer.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -109,7 +109,7 @@ class VideoCaptureServiceImpl::GpuDependenciesContext 
       this};
 };
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Intended usage of this class is to create viz::Gpu in utility process and
 // connect to viz::GpuClient of browser process, which will call to Gpu service.
 // Also, this class holds the viz::ContextProvider to listen and monitor Gpu
@@ -256,7 +256,7 @@ void VideoCaptureServiceImpl::LazyInitializeGpuDepende
   if (!gpu_dependencies_context_)
     gpu_dependencies_context_ = std::make_unique<GpuDependenciesContext>();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled()) {
     if (!viz_gpu_context_provider_) {
       viz_gpu_context_provider_ =
@@ -344,7 +344,7 @@ void VideoCaptureServiceImpl::OnGpuInfoUpdate(const CH
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void VideoCaptureServiceImpl::SetVizGpu(std::unique_ptr<viz::Gpu> viz_gpu) {
   viz_gpu_ = std::move(viz_gpu);
 }
