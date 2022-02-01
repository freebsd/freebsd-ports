--- chrome/browser/sync/sync_service_factory.cc.orig	2021-12-14 11:44:59 UTC
+++ chrome/browser/sync/sync_service_factory.cc
@@ -106,7 +106,7 @@ std::unique_ptr<KeyedService> BuildSyncService(
 // in lacros-chrome once build flag switch of lacros-chrome is
 // complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   syncer::SyncPrefs prefs(profile->GetPrefs());
   local_sync_backend_enabled = prefs.IsLocalSyncEnabled();
   UMA_HISTOGRAM_BOOLEAN("Sync.Local.Enabled", local_sync_backend_enabled);
@@ -124,7 +124,7 @@ std::unique_ptr<KeyedService> BuildSyncService(
 
     init_params.start_behavior = syncer::SyncServiceImpl::AUTO_START;
   }
-#endif  // defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS))
 
   if (!local_sync_backend_enabled) {
