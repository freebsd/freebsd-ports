--- chrome/browser/global_features.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/global_features.cc
@@ -44,7 +44,7 @@
 #include "chrome/browser/ui/tabs/tab_drag_api/desktop_tab_drag_impl/tab_drag_session_desktop_injector.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/default_browser/default_browser_manager.h"
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_manager.h"
 #include "chrome/browser/ui/webui/whats_new/whats_new_registrar.h"
@@ -56,7 +56,7 @@
 #include "chrome/browser/win/installer_downloader/installer_downloader_infobar_delegate.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/lifetime/scheduled_restart_manager.h"
 #endif
 
@@ -68,7 +68,7 @@
 #include "chrome/common/chrome_features.h"
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/lifetime/scheduled_restart_manager.h"
 #include "chrome/browser/ui/views/scheduled_restart/scheduled_restart_bubble_controller.h"
 #endif
@@ -191,7 +191,7 @@ void GlobalFeatures::PostBrowserProcessInit() {
   }
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   default_browser_manager_ =
       GetUserDataFactory()
           .CreateInstance<default_browser::DefaultBrowserManager>(
@@ -224,7 +224,7 @@ void GlobalFeatures::PostBrowserProcessInitCore() {
   }
 #endif
   system_permissions_platform_handle_ = CreateSystemPermissionsPlatformHandle();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/463742800): Migrate WhatsNewRegistry (and other non-core
   // features) to Init().
   whats_new_registry_ = CreateWhatsNewRegistry();
@@ -298,7 +298,7 @@ void GlobalFeatures::PostMainMessageLoopRun() {
   profile_launch_observer_.reset();
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   scheduled_restart_bubble_controller_.reset();
   scheduled_restart_manager_.reset();
 #endif
@@ -330,7 +330,7 @@ void GlobalFeatures::PostMainMessageLoopRun() {
 #endif
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DefaultBrowserPromptManager::GetInstance()->CloseAllPrompts(
       DefaultBrowserPromptManager::CloseReason::kDismiss);
   default_browser_manager_.reset();
@@ -350,7 +350,7 @@ GlobalFeatures::CreateSystemPermissionsPlatformHandle(
   return system_permission_settings::PlatformHandle::Create();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<whats_new::WhatsNewRegistry>
 GlobalFeatures::CreateWhatsNewRegistry() {
   return whats_new::CreateWhatsNewRegistry();
@@ -362,7 +362,7 @@ GlobalFeatures::CreateGlobalBrowserCollection() {
   return std::make_unique<GlobalBrowserCollection>();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<scheduled_restart::ScheduledRestartManager>
 GlobalFeatures::CreateScheduledRestartManager() {
   return std::make_unique<scheduled_restart::ScheduledRestartManager>(
