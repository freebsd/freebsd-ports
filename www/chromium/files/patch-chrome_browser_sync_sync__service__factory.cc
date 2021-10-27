--- chrome/browser/sync/sync_service_factory.cc.orig	2021-09-24 18:28:51 UTC
+++ chrome/browser/sync/sync_service_factory.cc
@@ -110,7 +110,7 @@ std::unique_ptr<KeyedService> BuildSyncService(
 // in lacros-chrome once build flag switch of lacros-chrome is
 // complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   syncer::SyncPrefs prefs(profile->GetPrefs());
   local_sync_backend_enabled = prefs.IsLocalSyncEnabled();
   UMA_HISTOGRAM_BOOLEAN("Sync.Local.Enabled", local_sync_backend_enabled);
@@ -128,7 +128,7 @@ std::unique_ptr<KeyedService> BuildSyncService(
 
     init_params.start_behavior = syncer::SyncServiceImpl::AUTO_START;
   }
-#endif  // defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS))
 
   if (!local_sync_backend_enabled) {
