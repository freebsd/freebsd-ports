--- third_party/blink/renderer/platform/graphics/canvas_2d_resource_provider.cc.orig	2026-08-31 10:59:09 UTC
+++ third_party/blink/renderer/platform/graphics/canvas_2d_resource_provider.cc
@@ -794,7 +794,7 @@ Canvas2DResourceProvider::CreateWithClear(
           gpu::SHARED_IMAGE_USAGE_CONCURRENT_READ_WRITE);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
   // dependent on canvas copies being RGBA (not BGRA).
   should_force_bgra8_to_rgba = true;
