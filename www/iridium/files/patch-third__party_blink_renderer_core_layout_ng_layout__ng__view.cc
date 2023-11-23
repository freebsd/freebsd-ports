--- third_party/blink/renderer/core/layout/ng/layout_ng_view.cc.orig	2023-11-22 14:00:11 UTC
+++ third_party/blink/renderer/core/layout/ng/layout_ng_view.cc
@@ -15,7 +15,7 @@
 #include "third_party/blink/renderer/core/svg/svg_document_extensions.h"
 #include "ui/display/screen_info.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/platform/fonts/font_cache.h"
 #endif
 
@@ -51,7 +51,7 @@ void LayoutNGView::UpdateLayout() {
     fragmentation_context_.Clear();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The font code in FontPlatformData does not have a direct connection to the
   // document, the frame or anything from which we could retrieve the device
   // scale factor. After using zoom for DSF, the GraphicsContext does only ever
