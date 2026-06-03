--- third_party/blink/renderer/platform/graphics/gpu/image_layer_bridge.cc.orig	2026-04-15 12:07:04 UTC
+++ third_party/blink/renderer/platform/graphics/gpu/image_layer_bridge.cc
@@ -45,7 +45,7 @@ scoped_refptr<StaticBitmapImage> MakeAccelerated(
     return source;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(b/330865436): On Linux, CanvasResourceProvider doesn't always check
   // for SCANOUT support correctly on X11 and it's never supported in
   // practice. Therefore, don't include it until this flow is reworked.
