--- src/chrome/browser/themes/theme_service_factory.cc.orig	2026-09-25 15:26:43 UTC
+++ src/chrome/browser/themes/theme_service_factory.cc
@@ -23,7 +23,7 @@
 #include "chrome/browser/themes/theme_helper_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/themes/theme_service_aura_linux.h"
 #endif
 
@@ -99,7 +99,7 @@
 ThemeServiceFactory::BuildServiceInstanceForBrowserContext(
     content::BrowserContext* profile) const {
   BRAVE_THEMESERVICEFACTORY_BUILDSERVICEINSTANCEFOR
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   using ThemeService = ThemeServiceAuraLinux;
 #endif
 
