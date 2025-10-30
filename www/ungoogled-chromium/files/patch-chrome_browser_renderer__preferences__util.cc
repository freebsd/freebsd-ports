--- chrome/browser/renderer_preferences_util.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/renderer_preferences_util.cc
@@ -38,7 +38,7 @@
 #include "ui/base/ui_base_features.h"
 #include "ui/native_theme/native_theme.h"
 
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #include "ui/linux/linux_ui.h"
@@ -109,7 +109,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
                               Profile* profile) {
   const PrefService* pref_service = profile->GetPrefs();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
   prefs->focus_ring_color = BUILDFLAG(IS_MAC) ? SkColorSetRGB(0x00, 0x5F, 0xCC)
@@ -123,7 +123,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
   prefs->inactive_selection_fg_color = SK_ColorBLACK;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile)) {
     if (ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme()) {
       linux_ui_theme->GetFocusRingColor(&prefs->focus_ring_color);
