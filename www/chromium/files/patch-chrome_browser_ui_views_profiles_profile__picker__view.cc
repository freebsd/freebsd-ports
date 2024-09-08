--- chrome/browser/ui/views/profiles/profile_picker_view.cc.orig	2024-08-26 12:06:38 UTC
+++ chrome/browser/ui/views/profiles/profile_picker_view.cc
@@ -87,7 +87,7 @@
 #include "chrome/browser/ui/views/profiles/first_run_flow_controller_lacros.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -117,7 +117,7 @@ class ProfilePickerWidget : public views::Widget {
     views::Widget::InitParams params(
         views::Widget::InitParams::NATIVE_WIDGET_OWNS_WIDGET);
     params.delegate = profile_picker_view_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.wm_class_name = shell_integration_linux::GetProgramClassName();
     params.wm_class_class = shell_integration_linux::GetProgramClassClass();
     params.wayland_app_id = params.wm_class_class;
