--- chrome/browser/devtools/devtools_eye_dropper.cc.orig	2017-08-01 23:43:54.195876000 +0200
+++ chrome/browser/devtools/devtools_eye_dropper.cc	2017-08-01 23:44:16.153565000 +0200
@@ -149,7 +149,7 @@
 // magnified projection only with centered hotspot.
 // Mac Retina requires cursor to be > 120px in order to render smoothly.
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const float kCursorSize = 63;
   const float kDiameter = 63;
   const float kHotspotOffset = 32;
