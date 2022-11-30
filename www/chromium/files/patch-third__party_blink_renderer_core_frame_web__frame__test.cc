--- third_party/blink/renderer/core/frame/web_frame_test.cc.orig	2022-11-30 08:12:58 UTC
+++ third_party/blink/renderer/core/frame/web_frame_test.cc
@@ -6414,7 +6414,7 @@ TEST_F(WebFrameTest, DISABLED_PositionForPointTest) {
   MoveCaretStaysHorizontallyAlignedWhenMoved
 #endif
 // TODO(crbug.com/1317375): Build these tests on all platforms.
-#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 TEST_F(WebFrameTest, MAYBE_SelectRangeStaysHorizontallyAlignedWhenMoved) {
   RegisterMockedHttpURLLoad("move_caret.html");
 
@@ -6811,7 +6811,7 @@ TEST_F(CompositedSelectionBoundsTest, LargeSelectionSc
 TEST_F(CompositedSelectionBoundsTest, LargeSelectionNoScroll) {
   RunTest("composited_selection_bounds_large_selection_noscroll.html");
 }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if !BUILDFLAG(IS_ANDROID)
 TEST_F(CompositedSelectionBoundsTest, Input) {
   web_view_helper_.GetWebView()->GetSettings()->SetDefaultFontSize(16);
