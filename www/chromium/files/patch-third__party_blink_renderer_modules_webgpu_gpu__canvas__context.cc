--- third_party/blink/renderer/modules/webgpu/gpu_canvas_context.cc.orig	2026-11-19 12:25:27 UTC
+++ third_party/blink/renderer/modules/webgpu/gpu_canvas_context.cc
@@ -299,7 +299,7 @@ GPUCanvasContext::PaintRenderingResultsToSnapshot(
 
   scoped_refptr<WebGPUMailboxTexture> front_buffer_texture;
   if (source_buffer == kFrontBuffer) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // By returning false here the canvas will show up as black in the scenarios
     // that copy the front buffer, such as printing.
     // TODO(crbug.com/40902474): Support concurrent SharedImage reads via Dawn
@@ -518,7 +518,7 @@ void GPUCanvasContext::configure(const GPUCanvasConfig
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (texture_descriptor_.format == wgpu::TextureFormat::BGRA8Unorm) {
     // WebGPU on vulkan with GL interop cannot support BGRA due to bugs in
     // mesa. See anglebug.com/40644739
@@ -1090,7 +1090,7 @@ scoped_refptr<StaticBitmapImage> GPUCanvasContext::Sna
   }
 
   viz::SharedImageFormat format = GetSharedImageFormat();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
   // dependent on canvas copies being RGBA (not BGRA).
   if (format != viz::SinglePlaneFormat::kRGBA_F16) {
