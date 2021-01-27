--- chrome/browser/sync/profile_sync_service_factory.cc.orig	2021-01-19 11:27:21 UTC
+++ chrome/browser/sync/profile_sync_service_factory.cc
@@ -202,7 +202,7 @@ KeyedService* ProfileSyncServiceFactory::BuildServiceI
 
 // Only check the local sync backend pref on the supported platforms of
 // Windows, Mac and Linux.
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
   syncer::SyncPrefs prefs(profile->GetPrefs());
   local_sync_backend_enabled = prefs.IsLocalSyncEnabled();
   UMA_HISTOGRAM_BOOLEAN("Sync.Local.Enabled", local_sync_backend_enabled);
@@ -220,7 +220,7 @@ KeyedService* ProfileSyncServiceFactory::BuildServiceI
 
     init_params.start_behavior = syncer::ProfileSyncService::AUTO_START;
   }
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
   if (!local_sync_backend_enabled) {
     // Always create the GCMProfileService instance such that we can listen to
