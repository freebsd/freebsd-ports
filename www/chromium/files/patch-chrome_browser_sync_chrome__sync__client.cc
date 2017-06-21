--- chrome/browser/sync/chrome_sync_client.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -653,7 +653,7 @@ void ChromeSyncClient::RegisterDesktopDataTypes(
   }
 #endif  // BUILDFLAG(ENABLE_APP_LIST)
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Dictionary sync is enabled by default.
   if (!disabled_types.Has(syncer::DICTIONARY)) {
     sync_service->RegisterDataTypeController(
