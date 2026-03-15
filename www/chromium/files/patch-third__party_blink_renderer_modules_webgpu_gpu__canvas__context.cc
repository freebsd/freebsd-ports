--- third_party/blink/renderer/modules/webgpu/gpu_canvas_context.cc.orig	2026-03-13 06:02:14 UTC
+++ third_party/blink/renderer/modules/webgpu/gpu_canvas_context.cc
@@ -269,7 +269,7 @@ GPUCanvasContext::PaintRenderingResultsToSnapshot(
 
   scoped_refptr<WebGPUMailboxTexture> front_buffer_texture;
   if (source_buffer == kFrontBuffer) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // By returning false here the canvas will show up as black in the scenarios
     // that copy the front buffer, such as printing.
     // TODO(crbug.com/40902474): Support concurrent SharedImage reads via Dawn
@@ -487,7 +487,7 @@ void GPUCanvasContext::configure(const GPUCanvasConfig
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (texture_descriptor_.format == wgpu::TextureFormat::BGRA8Unorm) {
     // WebGPU on vulkan with GL interop cannot support BGRA due to bugs in
     // mesa. See anglebug.com/40644739
