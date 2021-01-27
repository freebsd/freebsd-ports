--- third_party/blink/renderer/core/exported/web_view_impl.cc.orig	2021-01-19 11:50:55 UTC
+++ third_party/blink/renderer/core/exported/web_view_impl.cc
@@ -410,7 +410,7 @@ ui::mojom::blink::WindowOpenDisposition NavigationPoli
 #if !defined(OS_MAC) && !defined(OS_WIN)
 SkFontHinting RendererPreferencesToSkiaHinting(
     const blink::RendererPreferences& prefs) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!prefs.should_antialias_text) {
     // When anti-aliasing is off, GTK maps all non-zero hinting settings to
     // 'Normal' hinting so we do the same. Otherwise, folks who have 'Slight'
@@ -3185,12 +3185,12 @@ void WebViewImpl::UpdateFontRenderingFromRendererPrefs
       gfx::FontRenderParams::SUBPIXEL_RENDERING_NONE);
   WebFontRenderStyle::SetSubpixelPositioning(
       renderer_preferences_.use_subpixel_positioning);
-#if defined(OS_LINUX) && !defined(OS_ANDROID)
+#if (defined(OS_LINUX) && !defined(OS_ANDROID)) || defined(OS_BSD)
   if (!renderer_preferences_.system_font_family_name.empty()) {
     WebFontRenderStyle::SetSystemFontFamily(blink::WebString::FromUTF8(
         renderer_preferences_.system_font_family_name));
   }
-#endif  // defined(OS_LINUX) && !defined(OS_ANDROID)
+#endif  // (defined(OS_LINUX) && !defined(OS_ANDROID)) || defined(OS_BSD)
 #endif  // defined(OS_WIN)
 #endif  // !defined(OS_MAC)
 }
