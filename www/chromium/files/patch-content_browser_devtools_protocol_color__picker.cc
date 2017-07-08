--- content/browser/devtools/protocol/color_picker.cc.orig	2017-06-05 19:03:06 UTC
+++ content/browser/devtools/protocol/color_picker.cc
@@ -154,7 +154,7 @@ void ColorPicker::UpdateCursor() {
   // magnified projection only with centered hotspot.
   // Mac Retina requires cursor to be > 120px in order to render smoothly.
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const float kCursorSize = 63;
   const float kDiameter = 63;
   const float kHotspotOffset = 32;
