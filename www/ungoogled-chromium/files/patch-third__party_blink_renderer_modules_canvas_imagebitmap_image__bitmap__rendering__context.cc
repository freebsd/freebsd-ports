--- third_party/blink/renderer/modules/canvas/imagebitmap/image_bitmap_rendering_context.cc.orig	2026-08-13 07:41:05 UTC
+++ third_party/blink/renderer/modules/canvas/imagebitmap/image_bitmap_rendering_context.cc
@@ -59,7 +59,7 @@ scoped_refptr<StaticBitmapImage> ImageBitmapRenderingC
     return source;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(b/330865436): On Linux, CanvasResourceProvider doesn't always check
   // for SCANOUT support correctly on X11 and it's never supported in
   // practice. Therefore, don't include it until this flow is reworked.
