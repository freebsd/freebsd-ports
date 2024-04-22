--- third_party/blink/renderer/core/exported/web_view_impl.cc.orig	2024-03-22 14:16:19 UTC
+++ third_party/blink/renderer/core/exported/web_view_impl.cc
@@ -425,7 +425,7 @@ SkFontHinting RendererPreferencesToSkiaHinting(
     const blink::RendererPreferences& prefs) {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   if (!prefs.should_antialias_text) {
     // When anti-aliasing is off, GTK maps all non-zero hinting settings to
     // 'Normal' hinting so we do the same. Otherwise, folks who have 'Slight'
@@ -3376,7 +3376,7 @@ void WebViewImpl::UpdateFontRenderingFromRendererPrefs
       renderer_preferences_.use_subpixel_positioning);
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) && \
     !BUILDFLAG(IS_ANDROID)
   if (!renderer_preferences_.system_font_family_name.empty()) {
     WebFontRenderStyle::SetSystemFontFamily(blink::WebString::FromUTF8(
