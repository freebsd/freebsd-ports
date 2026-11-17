--- src/third_party/blink/renderer/modules/canvas/imagebitmap/image_bitmap_rendering_context.cc.orig	2026-10-18 18:43:23 UTC
+++ src/third_party/blink/renderer/modules/canvas/imagebitmap/image_bitmap_rendering_context.cc
@@ -70,7 +70,7 @@ scoped_refptr<StaticBitmapImage> ImageBi
     return source;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(b/330865436): On Linux, CanvasResourceProvider doesn't always check
   // for SCANOUT support correctly on X11 and it's never supported in
   // practice. Therefore, don't include it until this flow is reworked.
