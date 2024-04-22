--- third_party/blink/renderer/core/frame/web_frame_test.cc.orig	2024-02-04 14:46:08 UTC
+++ third_party/blink/renderer/core/frame/web_frame_test.cc
@@ -6468,7 +6468,7 @@ TEST_F(WebFrameTest, DISABLED_PositionForPointTest) {
 }
 
 #if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1090246): Fix these tests on Fuchsia and re-enable.
 // TODO(crbug.com/1317375): Build these tests on all platforms.
 #define MAYBE_SelectRangeStaysHorizontallyAlignedWhenMoved \
@@ -6877,7 +6877,7 @@ TEST_F(CompositedSelectionBoundsTest, LargeSelectionSc
 TEST_F(CompositedSelectionBoundsTest, LargeSelectionNoScroll) {
   RunTest("composited_selection_bounds_large_selection_noscroll.html");
 }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if !BUILDFLAG(IS_ANDROID)
 TEST_F(CompositedSelectionBoundsTest, Input) {
   web_view_helper_.GetWebView()->GetSettings()->SetDefaultFontSize(16);
