--- chrome/browser/themes/theme_service.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/browser/themes/theme_service.cc
@@ -72,7 +72,7 @@
 #include "extensions/browser/extension_registry_observer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -489,7 +489,7 @@ ThemeService::BrowserThemeProvider::GetColorProviderCo
         native_theme = ui::NativeTheme::GetInstanceForDarkUI();
       } else {
         native_theme = ui::NativeTheme::GetInstanceForNativeUi();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         if (const auto* linux_ui = views::LinuxUI::instance()) {
           native_theme =
               linux_ui->GetNativeTheme(delegate_->ShouldUseSystemTheme());
@@ -611,7 +611,7 @@ CustomThemeSupplier* ThemeService::GetThemeSupplier() 
 }
 
 bool ThemeService::ShouldUseSystemTheme() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return profile_->GetPrefs()->GetBoolean(prefs::kUsesSystemTheme);
 #else
   return false;
@@ -619,7 +619,7 @@ bool ThemeService::ShouldUseSystemTheme() const {
 }
 
 bool ThemeService::ShouldUseCustomFrame() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return profile_->GetPrefs()->GetBoolean(prefs::kUseCustomChromeFrame);
 #else
   return true;
