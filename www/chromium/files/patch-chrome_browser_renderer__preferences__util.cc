--- chrome/browser/renderer_preferences_util.cc.orig	2019-12-16 21:50:42 UTC
+++ chrome/browser/renderer_preferences_util.cc
@@ -30,7 +30,7 @@
 #include "ui/base/cocoa/defaults_utils.h"
 #endif
 
-#if defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #include "ui/views/linux_ui/linux_ui.h"
@@ -145,7 +145,7 @@ void UpdateFromSystemSettings(blink::mojom::RendererPr
     prefs->caret_blink_interval = interval;
 #endif
 
-#if defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   views::LinuxUI* linux_ui = views::LinuxUI::instance();
   if (linux_ui) {
     if (ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme()) {
@@ -164,7 +164,7 @@ void UpdateFromSystemSettings(blink::mojom::RendererPr
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
