--- third_party/blink/renderer/core/frame/web_frame_test.cc.orig	2021-04-22 08:28:10 UTC
+++ third_party/blink/renderer/core/frame/web_frame_test.cc
@@ -6053,7 +6053,7 @@ TEST_F(WebFrameTest, DISABLED_PositionForPointTest) {
   EXPECT_EQ(64, ComputeOffset(layout_object, 1000, 1000));
 }
 
-#if !defined(OS_MAC) && !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_MAC) && !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 TEST_F(WebFrameTest, SelectRangeStaysHorizontallyAlignedWhenMoved) {
   RegisterMockedHttpURLLoad("move_caret.html");
 
@@ -6427,7 +6427,7 @@ TEST_P(CompositedSelectionBoundsTest, Editable) {
 TEST_P(CompositedSelectionBoundsTest, EditableDiv) {
   RunTest("composited_selection_bounds_editable_div.html");
 }
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if !defined(OS_ANDROID)
 TEST_P(CompositedSelectionBoundsTest, Input) {
   // This test does not yet pass in CAP due to handling of
