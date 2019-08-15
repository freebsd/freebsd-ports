--- chrome/browser/sync/chrome_sync_client.cc.orig	2019-07-24 18:58:12 UTC
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -372,7 +372,7 @@ ChromeSyncClient::CreateDataTypeControllers(syncer::Sy
           dump_stack));
 #endif  // BUILDFLAG(ENABLE_APP_LIST)
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // Dictionary sync is enabled by default.
   if (!disabled_types.Has(syncer::DICTIONARY)) {
     controllers.push_back(
@@ -382,7 +382,7 @@ ChromeSyncClient::CreateDataTypeControllers(syncer::Sy
                            base::Unretained(this), syncer::DICTIONARY),
             dump_stack));
   }
-#endif  // defined(OS_LINUX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
   if (arc::IsArcAllowedForProfile(profile_) &&
