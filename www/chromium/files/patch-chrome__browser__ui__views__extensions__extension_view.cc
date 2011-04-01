--- ./chrome/browser/ui/views/extensions/extension_view.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/extensions/extension_view.cc	2010-12-20 20:15:08.000000000 +0100
@@ -14,7 +14,7 @@
 #include "chrome/browser/renderer_host/render_widget_host_view_win.h"
 #elif defined(TOUCH_UI)
 #include "chrome/browser/renderer_host/render_widget_host_view_views.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "chrome/browser/renderer_host/render_widget_host_view_gtk.h"
 #endif
 
