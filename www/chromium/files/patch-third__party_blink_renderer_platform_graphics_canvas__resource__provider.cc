--- third_party/blink/renderer/platform/graphics/canvas_resource_provider.cc.orig	2026-08-12 09:02:10 UTC
+++ third_party/blink/renderer/platform/graphics/canvas_resource_provider.cc
@@ -1713,7 +1713,7 @@ Canvas2DResourceProviderSharedImage::CreateWithClear(
           gpu::SHARED_IMAGE_USAGE_CONCURRENT_READ_WRITE);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
   // dependent on canvas copies being RGBA (not BGRA).
   should_force_bgra8_to_rgba = true;
@@ -1871,7 +1871,7 @@ CanvasNon2DResourceProviderSharedImage::Create(
           gpu::SHARED_IMAGE_USAGE_CONCURRENT_READ_WRITE);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
   // dependent on canvas copies being RGBA (not BGRA).
   should_force_bgra8_to_rgba = true;
