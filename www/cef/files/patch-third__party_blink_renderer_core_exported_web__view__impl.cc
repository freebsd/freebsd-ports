--- third_party/blink/renderer/core/exported/web_view_impl.cc.orig	2026-08-31 10:59:09 UTC
+++ third_party/blink/renderer/core/exported/web_view_impl.cc
@@ -196,7 +196,7 @@
 #include "ui/base/ui_base_features.h"
 #include "ui/gfx/geometry/skia_conversions.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "ui/native_theme/native_theme.h"
 #endif
 
@@ -402,7 +402,7 @@ void RecordPrerenderActivationSignalDelay(const String
 #if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_WIN)
 SkFontHinting RendererPreferencesToSkiaHinting(
     const blink::RendererPreferences& prefs) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!prefs.should_antialias_text) {
     // When anti-aliasing is off, GTK maps all non-zero hinting settings to
     // 'Normal' hinting so we do the same. Otherwise, folks who have 'Slight'
@@ -461,7 +461,7 @@ void MaybePreloadSystemFonts(Page* page) {
       FROM_HERE, BindOnce([]() { FontCache::MaybePreloadSystemFonts(); }));
 }
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 void UpdateUseOverlayScrollbar(bool use_overlay_scrollbar) {
   ui::NativeTheme::GetInstanceForWeb()->set_use_overlay_scrollbar(
       use_overlay_scrollbar);
@@ -3675,7 +3675,7 @@ void WebViewImpl::UpdateFontRenderingFromRendererPrefs
       gfx::FontRenderParams::SUBPIXEL_RENDERING_NONE);
   WebFontRenderStyle::SetSubpixelPositioning(
       renderer_preferences_.use_subpixel_positioning);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!renderer_preferences_.system_font_family_name.empty()) {
     WebFontRenderStyle::SetSystemFontFamily(blink::WebString::FromUtf8(
         renderer_preferences_.system_font_family_name));
@@ -3815,7 +3815,7 @@ void WebViewImpl::UpdateRendererPreferences(
       renderer_preferences_.selection_clipboard_buffer_available);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   GetSettings()->SetMiddleClickPasteAllowed(
       renderer_preferences_.middle_click_paste_allowed);
 #endif  // BUILDFLAG(IS_LINUX)
@@ -3823,7 +3823,7 @@ void WebViewImpl::UpdateRendererPreferences(
   SetExplicitlyAllowedPorts(
       renderer_preferences_.explicitly_allowed_network_ports);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (!ScrollbarTheme::MockScrollbarsEnabled()) {
     // DevTools emulation can update Blink's overlay scrollbar setting,
     // while OS theme updates can update NativeTheme before renderer preferences
