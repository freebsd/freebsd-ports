--- chrome/browser/ui/views/profiles/profile_picker_widget.cc.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/ui/views/profiles/profile_picker_widget.cc
@@ -11,7 +11,7 @@
 #include "chrome/browser/ui/views/profiles/profile_picker_view.h"
 #include "content/public/browser/web_contents.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -20,7 +20,7 @@ ProfilePickerWidget::ProfilePickerWidget(ProfilePicker
   views::Widget::InitParams params(
       views::Widget::InitParams::NATIVE_WIDGET_OWNS_WIDGET);
   params.delegate = profile_picker_view;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params.wm_class_name = shell_integration_linux::GetProgramClassName();
   params.wm_class_class = shell_integration_linux::GetProgramClassClass();
   params.wayland_app_id = params.wm_class_class;
