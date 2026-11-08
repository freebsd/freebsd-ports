--- third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc.orig	2026-09-25 15:26:43 UTC
+++ third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc
@@ -48,7 +48,7 @@ bool StructTraits<blink::mojom::RendererPreferencesDat
   out->use_custom_colors = data.use_custom_colors();
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   out->use_overlay_scrollbar = data.use_overlay_scrollbar();
 #endif
 
@@ -79,7 +79,7 @@ bool StructTraits<blink::mojom::RendererPreferencesDat
 
   out->send_subresource_notification = data.send_subresource_notification();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadSystemFontFamilyName(&out->system_font_family_name))
     return false;
 #endif
@@ -109,7 +109,7 @@ bool StructTraits<blink::mojom::RendererPreferencesDat
   out->selection_clipboard_buffer_available =
       data.selection_clipboard_buffer_available();
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   out->middle_click_paste_allowed = data.middle_click_paste_allowed();
 #endif
   out->plugin_fullscreen_allowed = data.plugin_fullscreen_allowed();
