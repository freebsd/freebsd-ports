--- chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc.orig    2015-05-20 09:55:54.547216000 -0400
+++ chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc	2015-05-20 09:56:51.726483000 -0400
@@ -34,7 +34,7 @@
 #include "ash/shell_window_ids.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -122,7 +122,7 @@
     const AppWindow::CreateParams& create_params,
     views::Widget::InitParams* init_params,
     views::Widget* widget) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   std::string app_name = web_app::GenerateApplicationNameFromExtensionId(
       app_window()->extension_id());
   // Set up a custom WM_CLASS for app windows. This allows task switchers in
