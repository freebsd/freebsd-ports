--- chrome/browser/renderer_preferences_util.cc.orig	2021-04-14 18:40:54 UTC
+++ chrome/browser/renderer_preferences_util.cc
@@ -38,7 +38,7 @@
 #include "ui/base/cocoa/defaults_utils.h"
 #endif
 
-#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #include "ui/views/linux_ui/linux_ui.h"
@@ -167,7 +167,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
     prefs->caret_blink_interval = interval;
 #endif
 
-#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   views::LinuxUI* linux_ui = views::LinuxUI::instance();
   if (linux_ui) {
     if (ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme()) {
@@ -186,7 +186,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_WIN)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
