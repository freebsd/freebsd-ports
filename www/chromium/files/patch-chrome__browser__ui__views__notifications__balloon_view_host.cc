--- ./chrome/browser/ui/views/notifications/balloon_view_host.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/notifications/balloon_view_host.cc	2010-12-20 20:15:08.000000000 +0100
@@ -10,7 +10,7 @@
 #if defined(OS_WIN)
 #include "chrome/browser/renderer_host/render_widget_host_view_win.h"
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #if defined(TOUCH_UI)
 #include "chrome/browser/renderer_host/render_widget_host_view_views.h"
 #else
@@ -21,7 +21,7 @@
 #if defined(OS_WIN)
 #include "views/widget/widget_win.h"
 #endif
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
@@ -74,7 +74,7 @@
   HWND hwnd = view_win->Create(parent_native_view_);
   view_win->ShowWindow(SW_SHOW);
   native_host_->Attach(hwnd);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #if defined(TOUCH_UI)
   RenderWidgetHostViewViews* view_views =
       static_cast<RenderWidgetHostViewViews*>(render_widget_host_view_);
