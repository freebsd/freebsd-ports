--- content/shell/renderer/web_test/test_runner.cc.orig	2020-07-07 21:58:16 UTC
+++ content/shell/renderer/web_test/test_runner.cc
@@ -73,7 +73,7 @@
 #include "ui/gfx/skia_util.h"
 #include "ui/gfx/test/icc_profiles.h"
 
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 #include "third_party/blink/public/platform/web_font_render_style.h"
 #endif
 
@@ -1842,7 +1842,7 @@ void TestRunner::Reset() {
   drag_image_.reset();
 
   blink::WebSecurityPolicy::ClearOriginAccessList();
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   blink::WebFontRenderStyle::SetSubpixelPositioning(false);
 #endif
   blink::ResetDomainRelaxationForTest();
@@ -2426,7 +2426,7 @@ void TestRunner::AddOriginAccessAllowListEntry(
 }
 
 void TestRunner::SetTextSubpixelPositioning(bool value) {
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // Since FontConfig doesn't provide a variable to control subpixel
   // positioning, we'll fall back to setting it globally for all fonts.
   blink::WebFontRenderStyle::SetSubpixelPositioning(value);
