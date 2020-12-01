--- third_party/blink/renderer/core/exported/web_frame_test.cc.orig	2020-11-13 06:36:47 UTC
+++ third_party/blink/renderer/core/exported/web_frame_test.cc
@@ -6054,7 +6054,7 @@ TEST_F(WebFrameTest, DISABLED_PositionForPointTest) {
   EXPECT_EQ(64, ComputeOffset(layout_object, 1000, 1000));
 }
 
-#if !defined(OS_MAC) && !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_MAC) && !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 TEST_F(WebFrameTest, SelectRangeStaysHorizontallyAlignedWhenMoved) {
   RegisterMockedHttpURLLoad("move_caret.html");
 
@@ -6387,7 +6387,7 @@ TEST_F(CompositedSelectionBoundsTest, Editable) {
 TEST_F(CompositedSelectionBoundsTest, EditableDiv) {
   RunTest("composited_selection_bounds_editable_div.html");
 }
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if !defined(OS_ANDROID)
 TEST_F(CompositedSelectionBoundsTest, Input) {
   RunTest("composited_selection_bounds_input.html");
