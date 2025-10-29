--- chrome/browser/accessibility/page_colors_controller.cc.orig	2025-10-28 14:29:43 UTC
+++ chrome/browser/accessibility/page_colors_controller.cc
@@ -11,7 +11,7 @@
 #include "components/prefs/pref_service.h"
 #include "ui/native_theme/native_theme.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_factory.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -88,7 +88,7 @@ void PageColorsController::OnPreferredContrastChanged(
 
 void PageColorsController::OnPageColorsChanged() {
   auto* native_theme = ui::NativeTheme::GetInstanceForNativeUi();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Allow the Linux native theme to update its state for page colors.
   if (auto* linux_ui_theme = ui::GetDefaultLinuxUiTheme()) {
     if (auto* linux_native_theme = linux_ui_theme->GetNativeTheme()) {
