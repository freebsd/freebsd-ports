--- chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc
@@ -17,7 +17,7 @@
 #include "ui/base/mojom/window_show_state.mojom.h"
 #include "ui/views/widget/widget.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -47,7 +47,7 @@ void ChromeNativeAppWindowViewsAura::OnBeforeWidgetIni
     const AppWindow::CreateParams& create_params,
     views::Widget::InitParams* init_params,
     views::Widget* widget) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string app_name =
       web_app::GenerateApplicationNameFromAppId(app_window()->extension_id());
   // Set up a custom WM_CLASS for app windows. This allows task switchers in
