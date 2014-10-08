--- chrome/browser/ui/views/apps/chrome_native_app_window_views.cc.orig	2014-10-06 09:32:59.000000000 +0200
+++ chrome/browser/ui/views/apps/chrome_native_app_window_views.cc	2014-10-06 09:40:11.000000000 +0200
@@ -29,7 +29,7 @@
 #include "ui/wm/core/easy_resize_window_targeter.h"
 #include "ui/wm/core/shadow_types.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX)  || defined(OS_BSD) || defined(OS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -217,7 +217,7 @@
     init_params.opacity = views::Widget::InitParams::TRANSLUCENT_WINDOW;
   init_params.keep_on_top = create_params.always_on_top;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS)  || defined(OS_BSD)
   // Set up a custom WM_CLASS for app windows. This allows task switchers in
   // X11 environments to distinguish them from main browser windows.
   init_params.wm_class_name = web_app::GetWMClassFromAppName(app_name);
