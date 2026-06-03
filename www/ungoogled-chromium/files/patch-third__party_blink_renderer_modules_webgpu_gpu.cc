--- third_party/blink/renderer/modules/webgpu/gpu.cc.orig	2026-02-15 10:01:45 UTC
+++ third_party/blink/renderer/modules/webgpu/gpu.cc
@@ -427,7 +427,7 @@ V8GPUTextureFormat GPU::getPreferredCanvasFormat() {
 }
 
 wgpu::TextureFormat GPU::GetPreferredCanvasFormat() {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Interop of vulkan and GL has mesa driver bugs for BGRA format
   // See anglebug.com/40644739
   return wgpu::TextureFormat::RGBA8Unorm;
