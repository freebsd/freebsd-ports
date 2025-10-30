--- chrome/browser/themes/theme_service.cc.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/themes/theme_service.cc
@@ -75,7 +75,7 @@
 #include "extensions/browser/extension_registry_observer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #include "ui/ozone/public/ozone_platform.h"  // nogncheck
 #endif
@@ -344,7 +344,7 @@ CustomThemeSupplier* ThemeService::GetThemeSupplier() 
 }
 
 bool ThemeService::ShouldUseCustomFrame() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::OzonePlatform::GetInstance()
            ->GetPlatformRuntimeProperties()
            .supports_server_side_window_decorations) {
