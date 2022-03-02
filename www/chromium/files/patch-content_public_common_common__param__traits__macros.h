--- content/public/common/common_param_traits_macros.h.orig	2022-02-28 16:54:41 UTC
+++ content/public/common/common_param_traits_macros.h
@@ -127,7 +127,7 @@ IPC_STRUCT_TRAITS_BEGIN(blink::RendererPreferences)
   IPC_STRUCT_TRAITS_MEMBER(accept_languages)
   IPC_STRUCT_TRAITS_MEMBER(plugin_fullscreen_allowed)
   IPC_STRUCT_TRAITS_MEMBER(caret_browsing_enabled)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(system_font_family_name)
 #endif
 #if BUILDFLAG(IS_WIN)
