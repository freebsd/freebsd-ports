--- src/third_party/blink/renderer/modules/webgpu/gpu.cc.orig	2026-10-18 18:43:23 UTC
+++ src/third_party/blink/renderer/modules/webgpu/gpu.cc
@@ -401,7 +401,7 @@ V8GPUTextureFormat GPU::getPreferredCanv
 }
 
 wgpu::TextureFormat GPU::GetPreferredCanvasFormat() {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Interop of vulkan and GL has mesa driver bugs for BGRA format
   // See anglebug.com/40644739
   return wgpu::TextureFormat::RGBA8Unorm;
