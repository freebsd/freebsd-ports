--- content/public/common/common_param_traits_macros.h.orig	2020-11-13 06:36:43 UTC
+++ content/public/common/common_param_traits_macros.h
@@ -138,7 +138,7 @@ IPC_STRUCT_TRAITS_BEGIN(blink::mojom::RendererPreferen
   IPC_STRUCT_TRAITS_MEMBER(accept_languages)
   IPC_STRUCT_TRAITS_MEMBER(plugin_fullscreen_allowed)
   IPC_STRUCT_TRAITS_MEMBER(caret_browsing_enabled)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(system_font_family_name)
   IPC_STRUCT_TRAITS_MEMBER(selection_clipboard_buffer_available)
 #endif
