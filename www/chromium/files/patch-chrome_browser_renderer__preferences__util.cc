--- chrome/browser/renderer_preferences_util.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/renderer_preferences_util.cc
@@ -42,12 +42,12 @@
 #include "ui/events/keycodes/keyboard_codes.h"
 #include "ui/native_theme/native_theme.h"
 
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "ui/linux/linux_ui.h"
@@ -116,7 +116,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
                               Profile* profile) {
   const PrefService* pref_service = profile->GetPrefs();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
   prefs->focus_ring_color = BUILDFLAG(IS_MAC) ? SkColorSetRGB(0x00, 0x5F, 0xCC)
@@ -130,7 +130,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
   prefs->inactive_selection_fg_color = SK_ColorBLACK;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile)) {
     if (ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme()) {
       linux_ui_theme->GetFocusRingColor(&prefs->focus_ring_color);
@@ -147,7 +147,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
 #endif  // BUILDFLAG(IS_LINUX)
 #endif  // BUILDFLAG(USE_AURA)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     prefs->middle_click_paste_allowed = linux_ui->PrimaryPasteEnabled();
   }
@@ -247,7 +247,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
   prefs->view_source_line_wrap_enabled =
       pref_service->GetBoolean(prefs::kViewSourceLineWrappingEnabled);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check the session type from the environment variable (XDG_SESSION_TYPE)
   // instead of the Ozone platform, because XWayland sessions still require
   // the portal eye dropper for reliable screen capture.
