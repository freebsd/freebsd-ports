--- chrome/browser/devtools/devtools_eye_dropper.cc.orig	2021-01-18 21:28:49 UTC
+++ chrome/browser/devtools/devtools_eye_dropper.cc
@@ -165,7 +165,7 @@ void DevToolsEyeDropper::UpdateCursor() {
 // magnified projection only with centered hotspot.
 // Mac Retina requires cursor to be > 120px in order to render smoothly.
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   const float kCursorSize = 63;
   const float kDiameter = 63;
   const float kHotspotOffset = 32;
