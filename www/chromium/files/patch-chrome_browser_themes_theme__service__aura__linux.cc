--- chrome/browser/themes/theme_service_aura_linux.cc.orig	2022-08-31 12:19:35 UTC
+++ chrome/browser/themes/theme_service_aura_linux.cc
@@ -13,7 +13,7 @@
 #include "ui/gfx/image/image.h"
 #include "ui/native_theme/native_theme_aura.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -53,14 +53,14 @@ void SystemThemeLinux::StartUsingTheme() {
 void SystemThemeLinux::StopUsingTheme() {
   pref_service_->SetBoolean(prefs::kUsesSystemTheme, false);
   // Have the former theme notify its observers of change.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance())
     linux_ui->GetNativeTheme(nullptr)->NotifyOnNativeThemeUpdated();
 #endif
 }
 
 bool SystemThemeLinux::GetColor(int id, SkColor* color) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     return linux_ui->GetColor(
         id, color, pref_service_->GetBoolean(prefs::kUseCustomChromeFrame));
@@ -70,7 +70,7 @@ bool SystemThemeLinux::GetColor(int id, SkColor* color
 }
 
 bool SystemThemeLinux::GetDisplayProperty(int id, int* result) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance())
     return linux_ui->GetDisplayProperty(id, result);
 #endif
