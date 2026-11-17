--- src/chrome/browser/global_features.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/global_features.cc
@@ -44,7 +44,7 @@
 #include "chrome/browser/ui/tabs/tab_drag_api/desktop_tab_drag_impl/tab_drag_session_desktop_injector.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This causes a gn error on Android builds, because gn does not understand
 // buildflags, so we include it only on platforms where it is used.
 #include "chrome/browser/default_browser/default_browser_manager.h"
@@ -59,7 +59,7 @@
 #include "chrome/browser/win/installer_downloader/installer_downloader_infobar_delegate.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/lifetime/scheduled_restart_manager.h"
 #endif
 
@@ -71,7 +71,7 @@
 #include "chrome/common/chrome_features.h"
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/lifetime/scheduled_restart_manager.h"
 #include "chrome/browser/ui/views/scheduled_restart/scheduled_restart_bubble_controller.h"
 #endif
@@ -193,7 +193,7 @@ void GlobalFeatures::PostBrowserProcessI
   }
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kScheduledRestart)) {
     scheduled_restart_manager_ = CreateScheduledRestartManager();
     scheduled_restart_bubble_controller_ =
@@ -219,7 +219,7 @@ void GlobalFeatures::PostBrowserProcessI
   }
 #endif
   system_permissions_platform_handle_ = CreateSystemPermissionsPlatformHandle();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/463742800): Migrate WhatsNewRegistry (and other non-core
   // features) to Init().
   whats_new_registry_ = CreateWhatsNewRegistry();
@@ -289,7 +289,7 @@ void GlobalFeatures::PostMainMessageLoop
   profile_launch_observer_.reset();
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   scheduled_restart_bubble_controller_.reset();
   scheduled_restart_manager_.reset();
 #endif
@@ -318,7 +318,7 @@ void GlobalFeatures::PostMainMessageLoop
   chrome_companero_host_.reset();
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DefaultBrowserPromptManager::GetInstance()->CloseAllPrompts(
       DefaultBrowserPromptManager::CloseReason::kDismiss);
 #endif
@@ -337,7 +337,7 @@ GlobalFeatures::CreateSystemPermissionsP
   return system_permission_settings::PlatformHandle::Create();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<whats_new::WhatsNewRegistry>
 GlobalFeatures::CreateWhatsNewRegistry() {
   return whats_new::CreateWhatsNewRegistry();
@@ -349,7 +349,7 @@ GlobalFeatures::CreateGlobalBrowserColle
   return std::make_unique<GlobalBrowserCollection>();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<scheduled_restart::ScheduledRestartManager>
 GlobalFeatures::CreateScheduledRestartManager() {
   return std::make_unique<scheduled_restart::ScheduledRestartManager>(
