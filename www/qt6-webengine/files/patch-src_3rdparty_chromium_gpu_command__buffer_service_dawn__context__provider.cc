--- src/3rdparty/chromium/gpu/command_buffer/service/dawn_context_provider.cc.orig	2023-10-11 18:22:24 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/dawn_context_provider.cc
@@ -145,7 +145,7 @@ wgpu::BackendType DawnContextProvider::GetDefaultBacke
   return base::FeatureList::IsEnabled(features::kSkiaGraphiteDawnUseD3D12)
              ? wgpu::BackendType::D3D12
              : wgpu::BackendType::D3D11;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return wgpu::BackendType::Vulkan;
 #elif BUILDFLAG(IS_APPLE)
   return wgpu::BackendType::Metal;
