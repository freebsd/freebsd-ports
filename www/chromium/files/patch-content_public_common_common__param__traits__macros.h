--- content/public/common/common_param_traits_macros.h.orig	2021-09-14 01:51:57 UTC
+++ content/public/common/common_param_traits_macros.h
@@ -122,7 +122,7 @@ IPC_STRUCT_TRAITS_BEGIN(blink::RendererPreferences)
   IPC_STRUCT_TRAITS_MEMBER(accept_languages)
   IPC_STRUCT_TRAITS_MEMBER(plugin_fullscreen_allowed)
   IPC_STRUCT_TRAITS_MEMBER(caret_browsing_enabled)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(system_font_family_name)
 #endif
 #if defined(OS_WIN)
