--- chrome/browser/themes/theme_service.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/themes/theme_service.cc
@@ -75,7 +75,7 @@
 #include "extensions/browser/extension_registry_observer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_factory.h"
 #include "ui/ozone/public/ozone_platform.h"  // nogncheck
@@ -259,7 +259,7 @@ std::unique_ptr<ui::ThemeProvider> ThemeService::Creat
 // static
 void ThemeService::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kSystemTheme,
                                 static_cast<int>(ui::GetDefaultSystemTheme()));
 #endif
@@ -390,7 +390,7 @@ CustomThemeSupplier* ThemeService::GetThemeSupplier() 
 }
 
 bool ThemeService::ShouldUseCustomFrame() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::OzonePlatform::GetInstance()
            ->GetPlatformRuntimeProperties()
            .supports_server_side_window_decorations) {
