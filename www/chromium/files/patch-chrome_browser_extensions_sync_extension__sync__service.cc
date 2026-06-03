--- chrome/browser/extensions/sync/extension_sync_service.cc.orig	2026-05-07 17:02:56 UTC
+++ chrome/browser/extensions/sync/extension_sync_service.cc
@@ -630,7 +630,7 @@ void ExtensionSyncService::ApplySyncData(
     AccountExtensionTracker::Get(profile_)->OnExtensionSyncDataReceived(id);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Chrome Apps are deprecated on WML, so we do not want to sync new apps
   // installed on other devices.
   if (extension_sync_data.is_app()) {
