--- content/public/common/common_param_traits_macros.h.orig	2019-04-30 22:22:47 UTC
+++ content/public/common/common_param_traits_macros.h
@@ -330,7 +330,7 @@ IPC_STRUCT_TRAITS_BEGIN(blink::mojom::RendererPreferen
   IPC_STRUCT_TRAITS_MEMBER(disable_client_blocked_error_page)
   IPC_STRUCT_TRAITS_MEMBER(plugin_fullscreen_allowed)
   IPC_STRUCT_TRAITS_MEMBER(network_contry_iso)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(system_font_family_name)
 #endif
 #if defined(OS_WIN)
