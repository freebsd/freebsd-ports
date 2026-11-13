--- gpu/command_buffer/service/dawn_context_provider.cc.orig	2026-11-11 14:44:17 UTC
+++ gpu/command_buffer/service/dawn_context_provider.cc
@@ -492,7 +492,7 @@ wgpu::BackendType DawnContextProvider::GetDefaultBacke
   }
 #if BUILDFLAG(IS_WIN)
   return wgpu::BackendType::D3D11;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return wgpu::BackendType::Vulkan;
 #elif BUILDFLAG(IS_APPLE)
   return wgpu::BackendType::Metal;
