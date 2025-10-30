--- chrome/browser/themes/theme_service_factory.cc.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/themes/theme_service_factory.cc
@@ -27,7 +27,7 @@
 #include "chrome/browser/themes/theme_helper_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/themes/theme_service_aura_linux.h"
 #include "ui/linux/linux_ui_factory.h"
 #endif
@@ -106,7 +106,7 @@ ThemeServiceFactory::~ThemeServiceFactory() = default;
 std::unique_ptr<KeyedService>
 ThemeServiceFactory::BuildServiceInstanceForBrowserContext(
     content::BrowserContext* profile) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   using ThemeService = ThemeServiceAuraLinux;
 #endif
 
@@ -118,7 +118,7 @@ ThemeServiceFactory::BuildServiceInstanceForBrowserCon
 
 void ThemeServiceFactory::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kSystemTheme,
                                 static_cast<int>(ui::GetDefaultSystemTheme()));
 #endif
