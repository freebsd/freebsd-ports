--- chrome/browser/themes/theme_service.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/themes/theme_service.cc
@@ -73,7 +73,7 @@
 #include "extensions/browser/extension_registry_observer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -512,7 +512,7 @@ ThemeService::BrowserThemeProvider::GetColorProviderCo
         native_theme = ui::NativeTheme::GetInstanceForDarkUI();
       } else {
         native_theme = ui::NativeTheme::GetInstanceForNativeUi();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         if (const auto* linux_ui = views::LinuxUI::instance()) {
           native_theme =
               linux_ui->GetNativeTheme(delegate_->ShouldUseSystemTheme());
@@ -632,7 +632,7 @@ CustomThemeSupplier* ThemeService::GetThemeSupplier() 
 }
 
 bool ThemeService::ShouldUseSystemTheme() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return profile_->GetPrefs()->GetBoolean(prefs::kUsesSystemTheme);
 #else
   return false;
@@ -640,7 +640,7 @@ bool ThemeService::ShouldUseSystemTheme() const {
 }
 
 bool ThemeService::ShouldUseCustomFrame() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return profile_->GetPrefs()->GetBoolean(prefs::kUseCustomChromeFrame);
 #else
   return true;
