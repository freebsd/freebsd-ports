--- third_party/blink/public/common/renderer_preferences/renderer_preferences.h.orig	2026-08-31 10:59:09 UTC
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences.h
@@ -54,7 +54,7 @@ struct BLINK_COMMON_EXPORT RendererPreferences {
   bool allow_cross_origin_auth_prompt{false};
   bool enable_do_not_track{false};
   bool enable_encrypted_media{true};
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool use_overlay_scrollbar{false};
 #endif
   blink::mojom::WebRtcIpHandlingPolicy webrtc_ip_handling_policy =
@@ -67,7 +67,7 @@ struct BLINK_COMMON_EXPORT RendererPreferences {
   UserAgentOverride user_agent_override;
   std::string accept_languages;
   bool send_subresource_notification{false};
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::string system_font_family_name;
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -85,7 +85,7 @@ struct BLINK_COMMON_EXPORT RendererPreferences {
 #if BUILDFLAG(IS_OZONE)
   bool selection_clipboard_buffer_available{false};
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool middle_click_paste_allowed{true};
 #endif
   bool plugin_fullscreen_allowed{true};
