--- chrome/browser/renderer_preferences_util.cc.orig	2026-01-14 08:33:23 UTC
+++ chrome/browser/renderer_preferences_util.cc
@@ -36,12 +36,12 @@
 #include "ui/base/ui_base_features.h"
 #include "ui/native_theme/native_theme.h"
 
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -110,7 +110,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
                               Profile* profile) {
   const PrefService* pref_service = profile->GetPrefs();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
   prefs->focus_ring_color = BUILDFLAG(IS_MAC) ? SkColorSetRGB(0x00, 0x5F, 0xCC)
@@ -124,7 +124,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
   prefs->inactive_selection_fg_color = SK_ColorBLACK;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile)) {
     if (ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme()) {
       linux_ui_theme->GetFocusRingColor(&prefs->focus_ring_color);
@@ -141,7 +141,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
 #endif  // BUILDFLAG(IS_LINUX)
 #endif  // BUILDFLAG(USE_AURA)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     prefs->middle_click_paste_allowed = linux_ui->PrimaryPasteEnabled();
   }
