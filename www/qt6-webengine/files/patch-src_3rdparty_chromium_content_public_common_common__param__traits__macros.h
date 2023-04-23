--- src/3rdparty/chromium/content/public/common/common_param_traits_macros.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/content/public/common/common_param_traits_macros.h
@@ -125,7 +125,7 @@ IPC_STRUCT_TRAITS_BEGIN(blink::RendererPreferences)
   IPC_STRUCT_TRAITS_MEMBER(accept_languages)
   IPC_STRUCT_TRAITS_MEMBER(plugin_fullscreen_allowed)
   IPC_STRUCT_TRAITS_MEMBER(caret_browsing_enabled)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(system_font_family_name)
 #endif
 #if BUILDFLAG(IS_WIN)
