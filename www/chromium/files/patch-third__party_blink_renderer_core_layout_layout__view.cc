--- third_party/blink/renderer/core/layout/layout_view.cc.orig	2019-03-17 20:57:47 UTC
+++ third_party/blink/renderer/core/layout/layout_view.cc
@@ -58,7 +58,7 @@
 #include "third_party/blink/renderer/platform/runtime_enabled_features.h"
 #include "third_party/blink/renderer/platform/transforms/transform_state.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "third_party/blink/renderer/platform/fonts/font_cache.h"
 #endif
 
@@ -321,7 +321,7 @@ void LayoutView::UpdateLayout() {
   DCHECK(!layout_state_);
   LayoutState root_layout_state(*this);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // The font code in FontPlatformData does not have a direct connection to the
   // document, the frame or anything from which we could retrieve the device
   // scale factor. After using zoom for DSF, the GraphicsContext does only ever
