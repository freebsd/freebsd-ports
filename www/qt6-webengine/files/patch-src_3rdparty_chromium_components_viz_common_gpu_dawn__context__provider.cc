--- src/3rdparty/chromium/components/viz/common/gpu/dawn_context_provider.cc.orig	2022-02-28 16:54:41 UTC
+++ src/3rdparty/chromium/components/viz/common/gpu/dawn_context_provider.cc
@@ -20,7 +20,7 @@ namespace {
 wgpu::BackendType GetDefaultBackendType() {
 #if BUILDFLAG(IS_WIN)
   return wgpu::BackendType::D3D12;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return wgpu::BackendType::Vulkan;
 #else
   NOTREACHED();
