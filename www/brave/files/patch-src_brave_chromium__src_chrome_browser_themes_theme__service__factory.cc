--- src/brave/chromium_src/chrome/browser/themes/theme_service_factory.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/chrome/browser/themes/theme_service_factory.cc
@@ -7,7 +7,7 @@
 
 #include "brave/browser/themes/brave_theme_service.h"
 
-#if !BUILDFLAG(IS_LINUX)
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #define BRAVE_THEMESERVICEFACTORY_BUILDSERVICEINSTANCEFOR \
   using ThemeService = BraveThemeService;
 #else
