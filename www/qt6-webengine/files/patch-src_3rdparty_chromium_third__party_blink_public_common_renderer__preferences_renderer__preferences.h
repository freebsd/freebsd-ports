--- src/3rdparty/chromium/third_party/blink/public/common/renderer_preferences/renderer_preferences.h.orig	2022-03-25 21:59:56 UTC
+++ src/3rdparty/chromium/third_party/blink/public/common/renderer_preferences/renderer_preferences.h
@@ -50,7 +50,7 @@ struct BLINK_COMMON_EXPORT RendererPreferences {
   bool webrtc_allow_legacy_tls_protocols{false};
   UserAgentOverride user_agent_override;
   std::string accept_languages;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::string system_font_family_name;
 #endif
 #if BUILDFLAG(IS_WIN)
