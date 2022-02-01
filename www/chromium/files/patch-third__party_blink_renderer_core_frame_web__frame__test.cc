--- third_party/blink/renderer/core/frame/web_frame_test.cc.orig	2021-12-31 00:57:41 UTC
+++ third_party/blink/renderer/core/frame/web_frame_test.cc
@@ -6079,7 +6079,7 @@ TEST_F(WebFrameTest, DISABLED_PositionForPointTest) {
   EXPECT_EQ(64, ComputeOffset(layout_object, 1000, 1000));
 }
 
-#if !defined(OS_MAC) && !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_MAC) && !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 TEST_F(WebFrameTest, SelectRangeStaysHorizontallyAlignedWhenMoved) {
   RegisterMockedHttpURLLoad("move_caret.html");
 
@@ -6449,7 +6449,7 @@ TEST_P(CompositedSelectionBoundsTest, SVGBasic) {
 TEST_P(CompositedSelectionBoundsTest, SVGTextWithFragments) {
   RunTest("composited_selection_bounds_svg_text_with_fragments.html");
 }
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if !defined(OS_ANDROID)
 TEST_P(CompositedSelectionBoundsTest, Input) {
   web_view_helper_.GetWebView()->GetSettings()->SetDefaultFontSize(16);
