--- components/viz/common/gpu/dawn_context_provider.cc.orig	2023-07-21 09:49:17 UTC
+++ components/viz/common/gpu/dawn_context_provider.cc
@@ -38,7 +38,7 @@ void LogFatal(WGPUDeviceLostReason reason,
 wgpu::BackendType GetDefaultBackendType() {
 #if BUILDFLAG(IS_WIN)
   return wgpu::BackendType::D3D11;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return wgpu::BackendType::Vulkan;
 #elif BUILDFLAG(IS_MAC)
   return wgpu::BackendType::Metal;
