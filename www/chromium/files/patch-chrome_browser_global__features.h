--- chrome/browser/global_features.h.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/global_features.h
@@ -26,7 +26,7 @@ class GlobalBrowserCollection;
 namespace system_permission_settings {
 class PlatformHandle;
 }  // namespace system_permission_settings
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace whats_new {
 class WhatsNewRegistry;
 }  // namespace whats_new
@@ -90,7 +90,7 @@ namespace on_device_translation {
 class OnDeviceTranslationInstaller;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace scheduled_restart {
 class ScheduledRestartBubbleController;
 class ScheduledRestartManager;
@@ -167,7 +167,7 @@ class GlobalFeatures {
   system_permissions_platform_handle() {
     return system_permissions_platform_handle_.get();
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   whats_new::WhatsNewRegistry* whats_new_registry() {
     return whats_new_registry_.get();
   }
@@ -240,7 +240,7 @@ class GlobalFeatures {
   }
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   scheduled_restart::ScheduledRestartBubbleController*
   scheduled_restart_bubble_controller() {
     return scheduled_restart_bubble_controller_.get();
@@ -270,12 +270,12 @@ class GlobalFeatures {
 
   virtual std::unique_ptr<system_permission_settings::PlatformHandle>
   CreateSystemPermissionsPlatformHandle();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual std::unique_ptr<whats_new::WhatsNewRegistry> CreateWhatsNewRegistry();
 #endif
   virtual std::unique_ptr<GlobalBrowserCollection>
   CreateGlobalBrowserCollection();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual std::unique_ptr<scheduled_restart::ScheduledRestartManager>
   CreateScheduledRestartManager();
 #endif
@@ -294,7 +294,7 @@ class GlobalFeatures {
 
   std::unique_ptr<system_permission_settings::PlatformHandle>
       system_permissions_platform_handle_;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<whats_new::WhatsNewRegistry> whats_new_registry_;
 
   std::unique_ptr<default_browser::DefaultBrowserManager>
@@ -359,7 +359,7 @@ class GlobalFeatures {
   std::unique_ptr<smart_restart::SmartRestartManager> smart_restart_manager_;
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<scheduled_restart::ScheduledRestartBubbleController>
       scheduled_restart_bubble_controller_;
   std::unique_ptr<scheduled_restart::ScheduledRestartManager>
