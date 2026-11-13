--- third_party/blink/renderer/platform/graphics/accelerated_static_bitmap_image.cc.orig	2026-11-11 14:44:17 UTC
+++ third_party/blink/renderer/platform/graphics/accelerated_static_bitmap_image.cc
@@ -155,7 +155,7 @@ scoped_refptr<StaticBitmapImage> AcceleratedStaticBitm
   bool should_force_bgra8_to_rgba =
       !shared_image_usage_flags.Has(gpu::SHARED_IMAGE_USAGE_WEBGPU_READ);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
   // dependent on canvas copies being RGBA (not BGRA).
   should_force_bgra8_to_rgba = true;
