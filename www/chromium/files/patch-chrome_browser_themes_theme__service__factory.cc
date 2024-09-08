--- chrome/browser/themes/theme_service_factory.cc.orig	2024-08-26 12:06:38 UTC
+++ chrome/browser/themes/theme_service_factory.cc
@@ -27,11 +27,11 @@
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/themes/theme_service_aura_linux.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui_factory.h"
 #endif
 
@@ -106,7 +106,7 @@ ThemeServiceFactory::~ThemeServiceFactory() = default;
 
 KeyedService* ThemeServiceFactory::BuildServiceInstanceFor(
     content::BrowserContext* profile) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   using ThemeService = ThemeServiceAuraLinux;
 #endif
 
@@ -120,9 +120,9 @@ void ThemeServiceFactory::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   ui::SystemTheme default_system_theme = ui::SystemTheme::kDefault;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   default_system_theme = ui::GetDefaultSystemTheme();
 #endif
   registry->RegisterIntegerPref(prefs::kSystemTheme,
