--- content/browser/devtools/protocol/color_picker.cc.orig	2016-07-20 22:03:24.000000000 +0300
+++ content/browser/devtools/protocol/color_picker.cc	2016-08-18 02:35:16.268652000 +0300
@@ -151,7 +151,7 @@
   // magnified projection only with centered hotspot.
   // Mac Retina requires cursor to be > 120px in order to render smoothly.
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const float kCursorSize = 63;
   const float kDiameter = 63;
   const float kHotspotOffset = 32;
