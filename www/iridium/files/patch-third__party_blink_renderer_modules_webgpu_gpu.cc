--- third_party/blink/renderer/modules/webgpu/gpu.cc.orig	2026-01-16 14:21:21 UTC
+++ third_party/blink/renderer/modules/webgpu/gpu.cc
@@ -419,7 +419,7 @@ V8GPUTextureFormat GPU::getPreferredCanvasFormat() {
 }
 
 wgpu::TextureFormat GPU::GetPreferredCanvasFormat() {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Interop of vulkan and GL has mesa driver bugs for BGRA format
   // See anglebug.com/40644739
   return wgpu::TextureFormat::RGBA8Unorm;
