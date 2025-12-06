--- chrome/browser/extensions/sync/extension_sync_service.cc.orig	2025-12-06 13:30:52 UTC
+++ chrome/browser/extensions/sync/extension_sync_service.cc
@@ -593,7 +593,7 @@ void ExtensionSyncService::ApplySyncData(
     AccountExtensionTracker::Get(profile_)->OnExtensionSyncDataReceived(id);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Chrome Apps are deprecated on WML, so we do not want to sync new apps
   // installed on other devices.
   if (extension_sync_data.is_app()) {
