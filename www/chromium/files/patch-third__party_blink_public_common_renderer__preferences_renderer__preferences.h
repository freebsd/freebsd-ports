--- third_party/blink/public/common/renderer_preferences/renderer_preferences.h.orig	2025-09-06 10:01:20 UTC
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences.h
@@ -66,7 +66,7 @@ struct BLINK_COMMON_EXPORT RendererPreferences {
   UserAgentOverride user_agent_override;
   std::string accept_languages;
   bool send_subresource_notification{false};
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::string system_font_family_name;
 #endif
 #if BUILDFLAG(IS_WIN)
