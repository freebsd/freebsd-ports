--- third_party/blink/renderer/platform/graphics/gpu/webgpu_shared_image_wrapper_cache.cc.orig	2026-09-25 15:26:43 UTC
+++ third_party/blink/renderer/platform/graphics/gpu/webgpu_shared_image_wrapper_cache.cc
@@ -398,7 +398,7 @@ WebGpuSharedImageWrapperCache::LeaseWebGpuSharedImageW
       return nullptr;
     }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
     // dependent on canvas copies being RGBA (not BGRA).
     if (format != viz::SinglePlaneFormat::kRGBA_F16) {
