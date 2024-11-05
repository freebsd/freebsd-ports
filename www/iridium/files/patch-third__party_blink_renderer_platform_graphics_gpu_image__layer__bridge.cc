--- third_party/blink/renderer/platform/graphics/gpu/image_layer_bridge.cc.orig	2024-11-04 08:56:03 UTC
+++ third_party/blink/renderer/platform/graphics/gpu/image_layer_bridge.cc
@@ -49,7 +49,7 @@ scoped_refptr<StaticBitmapImage> MakeAccelerated(
   const auto paint_image = source->PaintImageForCurrentFrame();
   const auto image_info = paint_image.GetSkImageInfo().makeWH(
       source->Size().width(), source->Size().height());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(b/330865436): On Linux, CanvasResourceProvider doesn't always check
   // for SCANOUT support correctly on X11 and it's never supported in
   // practice. Therefore, don't include it until this flow is reworked.
