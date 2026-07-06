--- third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc.orig	2026-06-05 13:45:06 UTC
+++ third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc
@@ -6605,7 +6605,7 @@ void WebGLRenderingContextBase::TexImageHelperMediaVid
       params.function_id == kTexImage2D ||
       (params.function_id == kTexSubImage2D &&
        base::FeatureList::IsEnabled(kAllowGpuUploadForTexSubImageOnAndroid));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/1181562): TexSubImage2D via the GPU path performs poorly on
   // Linux when used with frames backed by SharedImages holding shared memory.
   // We don't have a way to differentiate this case from that of true texture
