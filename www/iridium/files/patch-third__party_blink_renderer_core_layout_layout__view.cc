--- third_party/blink/renderer/core/layout/layout_view.cc.orig	2026-11-17 21:17:00 UTC
+++ third_party/blink/renderer/core/layout/layout_view.cc
@@ -78,7 +78,7 @@
 #include "ui/display/screen_info.h"
 #include "ui/gfx/geometry/quad_f.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/platform/fonts/font_cache.h"
 #endif
 
@@ -841,7 +841,7 @@ void LayoutView::LayoutRoot() {
     intrinsic_logical_widths_ = LogicalWidth();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The font code in FontPlatformData does not have a direct connection to the
   // document, the frame or anything from which we could retrieve the device
   // scale factor. After using zoom for DSF, the GraphicsContext does only ever
