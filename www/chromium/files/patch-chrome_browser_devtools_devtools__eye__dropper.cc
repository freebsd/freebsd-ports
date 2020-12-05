--- chrome/browser/devtools/devtools_eye_dropper.cc.orig	2020-11-13 06:36:36 UTC
+++ chrome/browser/devtools/devtools_eye_dropper.cc
@@ -163,7 +163,7 @@ void DevToolsEyeDropper::UpdateCursor() {
 // magnified projection only with centered hotspot.
 // Mac Retina requires cursor to be > 120px in order to render smoothly.
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   const float kCursorSize = 63;
   const float kDiameter = 63;
   const float kHotspotOffset = 32;
