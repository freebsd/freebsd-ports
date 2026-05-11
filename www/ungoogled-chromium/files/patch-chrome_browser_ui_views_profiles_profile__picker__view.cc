--- chrome/browser/ui/views/profiles/profile_picker_view.cc.orig	2026-05-09 18:09:27 UTC
+++ chrome/browser/ui/views/profiles/profile_picker_view.cc
@@ -88,7 +88,7 @@
 #include "chrome/browser/global_keyboard_shortcuts_mac.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -113,7 +113,7 @@ class ProfilePickerWidget : public views::Widget {
     views::Widget::InitParams params(
         views::Widget::InitParams::NATIVE_WIDGET_OWNS_WIDGET);
     params.delegate = profile_picker_view;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.wm_class_name = shell_integration_linux::GetProgramClassName();
     params.wm_class_class = shell_integration_linux::GetProgramClassClass();
     params.wayland_app_id = params.wm_class_class;
