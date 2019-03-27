--- src/3rdparty/chromium/content/common/view_messages.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/common/view_messages.h
@@ -221,7 +221,7 @@ IPC_STRUCT_TRAITS_BEGIN(content::RendererPreferences)
   IPC_STRUCT_TRAITS_MEMBER(disable_client_blocked_error_page)
   IPC_STRUCT_TRAITS_MEMBER(plugin_fullscreen_allowed)
   IPC_STRUCT_TRAITS_MEMBER(network_contry_iso)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(system_font_family_name)
 #endif
 #if defined(OS_WIN)
