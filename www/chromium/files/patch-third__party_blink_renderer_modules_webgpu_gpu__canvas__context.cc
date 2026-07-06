--- third_party/blink/renderer/modules/webgpu/gpu_canvas_context.cc.orig	2026-07-01 06:24:19 UTC
+++ third_party/blink/renderer/modules/webgpu/gpu_canvas_context.cc
@@ -274,7 +274,7 @@ GPUCanvasContext::PaintRenderingResultsToSnapshot(
 
   scoped_refptr<WebGPUMailboxTexture> front_buffer_texture;
   if (source_buffer == kFrontBuffer) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // By returning false here the canvas will show up as black in the scenarios
     // that copy the front buffer, such as printing.
     // TODO(crbug.com/40902474): Support concurrent SharedImage reads via Dawn
@@ -491,7 +491,7 @@ void GPUCanvasContext::configure(const GPUCanvasConfig
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (texture_descriptor_.format == wgpu::TextureFormat::BGRA8Unorm) {
     // WebGPU on vulkan with GL interop cannot support BGRA due to bugs in
     // mesa. See anglebug.com/40644739
