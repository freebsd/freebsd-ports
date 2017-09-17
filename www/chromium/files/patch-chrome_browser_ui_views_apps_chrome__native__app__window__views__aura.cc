--- chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc.orig	2017-09-05 21:05:14.000000000 +0200
+++ chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc	2017-09-06 18:35:55.806325000 +0200
@@ -19,7 +19,7 @@
 #include "ui/gfx/image/image_skia.h"
 #include "ui/views/widget/widget.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
