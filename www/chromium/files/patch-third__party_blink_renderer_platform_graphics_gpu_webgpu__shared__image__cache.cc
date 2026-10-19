--- third_party/blink/renderer/platform/graphics/gpu/webgpu_shared_image_cache.cc.orig	2026-10-18 13:29:39 UTC
+++ third_party/blink/renderer/platform/graphics/gpu/webgpu_shared_image_cache.cc
@@ -147,7 +147,7 @@ WebGpuSharedImageCache::LeaseSharedImage(viz::SharedIm
       return nullptr;
     }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
     // dependent on canvas copies being RGBA (not BGRA).
     if (format != viz::SinglePlaneFormat::kRGBA_F16) {
