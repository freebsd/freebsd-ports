--- chrome/browser/ui/views/apps/chrome_native_app_window_views.cc.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/ui/views/apps/chrome_native_app_window_views.cc
@@ -29,7 +29,7 @@
 #include "ui/wm/core/easy_resize_window_targeter.h"
 #include "ui/wm/core/shadow_types.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -219,7 +219,7 @@
   init_params.visible_on_all_workspaces =
       create_params.visible_on_all_workspaces;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   // Set up a custom WM_CLASS for app windows. This allows task switchers in
   // X11 environments to distinguish them from main browser windows.
   init_params.wm_class_name = web_app::GetWMClassFromAppName(app_name);
