--- third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h.orig	2026-09-25 15:26:43 UTC
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h
@@ -131,7 +131,7 @@ struct BLINK_COMMON_EXPORT
   }
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   static const bool& use_overlay_scrollbar(
       const ::blink::RendererPreferences& data) {
     return data.use_overlay_scrollbar;
@@ -183,7 +183,7 @@ struct BLINK_COMMON_EXPORT
     return data.send_subresource_notification;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static const std::string& system_font_family_name(
       const ::blink::RendererPreferences& data) {
     return data.system_font_family_name;
@@ -197,7 +197,7 @@ struct BLINK_COMMON_EXPORT
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static const bool& middle_click_paste_allowed(
       const ::blink::RendererPreferences& data) {
     return data.middle_click_paste_allowed;
