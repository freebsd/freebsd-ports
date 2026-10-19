--- chrome/browser/themes/theme_service.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/themes/theme_service.cc
@@ -92,7 +92,7 @@
 #include "extensions/common/extension_set.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/time/time.h"
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_factory.h"
@@ -309,7 +309,7 @@ std::unique_ptr<ui::ThemeProvider> ThemeService::Creat
 // static
 void ThemeService::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kSystemTheme,
                                 static_cast<int>(ui::GetDefaultSystemTheme()));
 #endif
@@ -442,7 +442,7 @@ CustomThemeSupplier* ThemeService::GetThemeSupplier() 
 }
 
 bool ThemeService::ShouldUseCustomFrame() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::OzonePlatform::GetInstance()
            ->GetPlatformRuntimeProperties()
            .supports_server_side_window_decorations) {
