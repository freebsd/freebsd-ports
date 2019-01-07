--- content/public/common/common_param_traits_macros.h.orig	2018-12-13 21:04:53.822520000 +0100
+++ content/public/common/common_param_traits_macros.h	2018-12-13 21:05:25.292903000 +0100
@@ -321,7 +321,7 @@
   IPC_STRUCT_TRAITS_MEMBER(disable_client_blocked_error_page)
   IPC_STRUCT_TRAITS_MEMBER(plugin_fullscreen_allowed)
   IPC_STRUCT_TRAITS_MEMBER(network_contry_iso)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(system_font_family_name)
 #endif
 #if defined(OS_WIN)
