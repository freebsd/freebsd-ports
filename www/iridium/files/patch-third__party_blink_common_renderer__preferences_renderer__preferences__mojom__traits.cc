--- third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc.orig	2026-01-16 14:21:21 UTC
+++ third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc
@@ -78,7 +78,7 @@ bool StructTraits<blink::mojom::RendererPreferencesDat
 
   out->send_subresource_notification = data.send_subresource_notification();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadSystemFontFamilyName(&out->system_font_family_name))
     return false;
 #endif
@@ -117,7 +117,7 @@ bool StructTraits<blink::mojom::RendererPreferencesDat
   out->selection_clipboard_buffer_available =
       data.selection_clipboard_buffer_available();
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   out->middle_click_paste_allowed = data.middle_click_paste_allowed();
 #endif
   out->plugin_fullscreen_allowed = data.plugin_fullscreen_allowed();
