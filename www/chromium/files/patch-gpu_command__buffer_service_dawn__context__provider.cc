--- gpu/command_buffer/service/dawn_context_provider.cc.orig	2023-09-13 12:11:42 UTC
+++ gpu/command_buffer/service/dawn_context_provider.cc
@@ -53,7 +53,7 @@ wgpu::BackendType GetDefaultBackendType() {
   return base::FeatureList::IsEnabled(features::kSkiaGraphiteDawnUseD3D12)
              ? wgpu::BackendType::D3D12
              : wgpu::BackendType::D3D11;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return wgpu::BackendType::Vulkan;
 #elif BUILDFLAG(IS_APPLE)
   return wgpu::BackendType::Metal;
