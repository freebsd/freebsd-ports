--- third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h.orig	2026-01-14 08:33:23 UTC
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h
@@ -185,7 +185,7 @@ struct BLINK_COMMON_EXPORT
     return data.send_subresource_notification;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static const std::string& system_font_family_name(
       const ::blink::RendererPreferences& data) {
     return data.system_font_family_name;
@@ -199,7 +199,7 @@ struct BLINK_COMMON_EXPORT
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static const bool& middle_click_paste_allowed(
       const ::blink::RendererPreferences& data) {
     return data.middle_click_paste_allowed;
