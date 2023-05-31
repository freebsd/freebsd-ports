--- components/viz/common/gpu/dawn_context_provider.cc.orig	2023-05-31 08:12:17 UTC
+++ components/viz/common/gpu/dawn_context_provider.cc
@@ -23,7 +23,7 @@ namespace {
 wgpu::BackendType GetDefaultBackendType() {
 #if BUILDFLAG(IS_WIN)
   return wgpu::BackendType::D3D12;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return wgpu::BackendType::Vulkan;
 #elif BUILDFLAG(IS_MAC)
   return wgpu::BackendType::Metal;
