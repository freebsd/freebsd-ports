--- chrome/browser/sync/chrome_sync_client.cc.orig	2019-10-21 19:06:23 UTC
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -389,7 +389,7 @@ ChromeSyncClient::CreateDataTypeControllers(syncer::Sy
           GetSyncableServiceForType(syncer::APP_LIST), dump_stack));
 #endif  // BUILDFLAG(ENABLE_APP_LIST)
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // Dictionary sync is enabled by default.
   if (!disabled_types.Has(syncer::DICTIONARY)) {
     controllers.push_back(
@@ -397,7 +397,7 @@ ChromeSyncClient::CreateDataTypeControllers(syncer::Sy
             syncer::DICTIONARY, GetModelTypeStoreService()->GetStoreFactory(),
             GetSyncableServiceForType(syncer::DICTIONARY), dump_stack));
   }
-#endif  // defined(OS_LINUX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
   if (arc::IsArcAllowedForProfile(profile_) &&
