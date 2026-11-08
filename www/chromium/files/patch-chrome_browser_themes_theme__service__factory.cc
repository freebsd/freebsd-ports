--- chrome/browser/themes/theme_service_factory.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/themes/theme_service_factory.cc
@@ -28,7 +28,7 @@
 #include "chrome/browser/themes/theme_helper_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/themes/theme_service_aura_linux.h"
 #endif
 
@@ -107,7 +107,7 @@ ThemeServiceFactory::~ThemeServiceFactory() = default;
 std::unique_ptr<KeyedService>
 ThemeServiceFactory::BuildServiceInstanceForBrowserContext(
     content::BrowserContext* profile) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   using ThemeService = ThemeServiceAuraLinux;
 #endif
 
