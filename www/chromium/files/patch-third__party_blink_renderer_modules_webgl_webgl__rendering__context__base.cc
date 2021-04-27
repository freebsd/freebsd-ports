--- third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc.orig	2021-04-22 08:29:16 UTC
+++ third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc
@@ -6035,7 +6035,7 @@ void WebGLRenderingContextBase::TexImageHelperMediaVid
   // TODO(crbug.com/1181993): Even TexImage2D doesn't seem to work reliably with
   // the GPU path.
   const bool function_supports_gpu_teximage = false;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // TODO(crbug.com/1181562): TexSubImage2D via the GPU path performs poorly on
   // Linux when used with ShMem GpuMemoryBuffer backed frames. We don't have a
   // way to differentiate between true texture backed frames and ShMem GMBs, so
