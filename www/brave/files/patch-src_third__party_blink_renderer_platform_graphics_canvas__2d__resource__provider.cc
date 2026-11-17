--- src/third_party/blink/renderer/platform/graphics/canvas_2d_resource_provider.cc.orig	2026-10-18 18:43:23 UTC
+++ src/third_party/blink/renderer/platform/graphics/canvas_2d_resource_provider.cc
@@ -773,7 +773,7 @@ Canvas2DResourceProvider::CreateWithClea
           gpu::SHARED_IMAGE_USAGE_CONCURRENT_READ_WRITE);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
   // dependent on canvas copies being RGBA (not BGRA).
   should_force_bgra8_to_rgba = true;
