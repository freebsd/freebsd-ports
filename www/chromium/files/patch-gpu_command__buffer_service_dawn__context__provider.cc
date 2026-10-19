--- gpu/command_buffer/service/dawn_context_provider.cc.orig	2026-10-18 13:29:39 UTC
+++ gpu/command_buffer/service/dawn_context_provider.cc
@@ -484,7 +484,7 @@ wgpu::BackendType DawnContextProvider::GetDefaultBacke
   }
 #if BUILDFLAG(IS_WIN)
   return wgpu::BackendType::D3D11;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return wgpu::BackendType::Vulkan;
 #elif BUILDFLAG(IS_APPLE)
   return wgpu::BackendType::Metal;
