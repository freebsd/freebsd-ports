--- chrome/browser/sync/chrome_sync_client.cc.orig	2017-01-26 00:49:09 UTC
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -578,7 +578,7 @@ void ChromeSyncClient::RegisterDesktopDa
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Dictionary sync is enabled by default.
   if (!disabled_types.Has(syncer::DICTIONARY)) {
     sync_service->RegisterDataTypeController(
