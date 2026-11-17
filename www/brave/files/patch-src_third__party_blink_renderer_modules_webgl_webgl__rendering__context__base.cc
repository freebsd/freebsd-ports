--- src/third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc.orig	2026-10-18 18:43:23 UTC
+++ src/third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc
@@ -6733,7 +6733,7 @@ void WebGLRenderingContextBase::TexImage
   // unmultiply has been requested or we need to never premultiply for Image
   // creation from a VideoFrame.
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/1181562): TexSubImage2D via the GPU path performs poorly on
   // Linux when used with frames backed by SharedImages holding shared memory.
   // We don't have a way to differentiate this case from that of true texture
