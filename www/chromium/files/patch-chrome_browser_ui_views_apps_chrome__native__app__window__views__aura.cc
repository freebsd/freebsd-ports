--- chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc.orig	2021-01-19 11:28:04 UTC
+++ chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc
@@ -19,7 +19,7 @@
 #include "ui/gfx/image/image_skia.h"
 #include "ui/views/widget/widget.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -56,7 +56,7 @@ void ChromeNativeAppWindowViewsAura::OnBeforeWidgetIni
     const AppWindow::CreateParams& create_params,
     views::Widget::InitParams* init_params,
     views::Widget* widget) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   std::string app_name =
       web_app::GenerateApplicationNameFromAppId(app_window()->extension_id());
   // Set up a custom WM_CLASS for app windows. This allows task switchers in
@@ -66,7 +66,7 @@ void ChromeNativeAppWindowViewsAura::OnBeforeWidgetIni
   init_params->wm_class_class = shell_integration_linux::GetProgramClassClass();
   const char kX11WindowRoleApp[] = "app";
   init_params->wm_role_name = std::string(kX11WindowRoleApp);
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
   ChromeNativeAppWindowViews::OnBeforeWidgetInit(create_params, init_params,
                                                  widget);
