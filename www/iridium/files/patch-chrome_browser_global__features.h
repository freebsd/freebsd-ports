--- chrome/browser/global_features.h.orig	2026-01-16 14:21:21 UTC
+++ chrome/browser/global_features.h
@@ -16,7 +16,7 @@
 namespace system_permission_settings {
 class PlatformHandle;
 }  // namespace system_permission_settings
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace whats_new {
 class WhatsNewRegistry;
 }  // namespace whats_new
@@ -91,7 +91,7 @@ class GlobalFeatures {
   system_permissions_platform_handle() {
     return system_permissions_platform_handle_.get();
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   whats_new::WhatsNewRegistry* whats_new_registry() {
     return whats_new_registry_.get();
   }
@@ -158,7 +158,7 @@ class GlobalFeatures {
 
   virtual std::unique_ptr<system_permission_settings::PlatformHandle>
   CreateSystemPermissionsPlatformHandle();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual std::unique_ptr<whats_new::WhatsNewRegistry> CreateWhatsNewRegistry();
 #endif
 
@@ -170,7 +170,7 @@ class GlobalFeatures {
 
   std::unique_ptr<system_permission_settings::PlatformHandle>
       system_permissions_platform_handle_;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<whats_new::WhatsNewRegistry> whats_new_registry_;
 
   std::unique_ptr<default_browser::DefaultBrowserManager>
