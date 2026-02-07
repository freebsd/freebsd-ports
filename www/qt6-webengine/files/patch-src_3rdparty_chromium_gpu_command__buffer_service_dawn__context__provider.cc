--- src/3rdparty/chromium/gpu/command_buffer/service/dawn_context_provider.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/dawn_context_provider.cc
@@ -341,7 +341,7 @@ wgpu::BackendType DawnContextProvider::GetDefaultBacke
   return base::FeatureList::IsEnabled(features::kSkiaGraphiteDawnUseD3D12)
              ? wgpu::BackendType::D3D12
              : wgpu::BackendType::D3D11;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return wgpu::BackendType::Vulkan;
 #elif BUILDFLAG(IS_APPLE)
   return wgpu::BackendType::Metal;
