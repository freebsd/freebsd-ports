--- third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h.orig	2022-03-28 18:11:04 UTC
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h
@@ -157,7 +157,7 @@ struct BLINK_COMMON_EXPORT
     return data.accept_languages;
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static const std::string& system_font_family_name(
       const ::blink::RendererPreferences& data) {
     return data.system_font_family_name;
