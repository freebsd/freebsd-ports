--- chrome/browser/themes/theme_service.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/themes/theme_service.cc
@@ -72,7 +72,7 @@
 #include "extensions/browser/extension_registry_observer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #include "ui/ozone/public/ozone_platform.h"  // nogncheck
 #endif
@@ -331,7 +331,7 @@ CustomThemeSupplier* ThemeService::GetThemeSupplier() 
 }
 
 bool ThemeService::ShouldUseCustomFrame() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::OzonePlatform::GetInstance()
            ->GetPlatformRuntimeProperties()
            .supports_server_side_window_decorations) {
