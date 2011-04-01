--- ./chrome/browser/ui/views/frame/opaque_browser_frame_view.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/frame/opaque_browser_frame_view.cc	2010-12-20 20:15:08.000000000 +0100
@@ -28,7 +28,7 @@
 #include "views/window/window_resources.h"
 #include "views/window/window_shape.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "views/window/hit_test.h"
 #endif
 
