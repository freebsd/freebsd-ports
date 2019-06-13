--- content/shell/test_runner/test_runner.cc.orig	2019-06-04 18:55:23 UTC
+++ content/shell/test_runner/test_runner.cc
@@ -66,7 +66,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/skia_util.h"
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 #include "third_party/blink/public/platform/web_font_render_style.h"
 #endif
 
@@ -1546,7 +1546,7 @@ void TestRunner::Reset() {
   drag_image_.reset();
 
   blink::WebSecurityPolicy::ClearOriginAccessList();
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
   blink::WebFontRenderStyle::SetSubpixelPositioning(false);
 #endif
 
@@ -2075,7 +2075,7 @@ void TestRunner::AddOriginAccessAllowListEntry(
 }
 
 void TestRunner::SetTextSubpixelPositioning(bool value) {
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // Since FontConfig doesn't provide a variable to control subpixel
   // positioning, we'll fall back to setting it globally for all fonts.
   blink::WebFontRenderStyle::SetSubpixelPositioning(value);
