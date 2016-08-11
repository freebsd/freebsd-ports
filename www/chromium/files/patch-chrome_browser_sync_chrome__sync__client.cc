--- chrome/browser/sync/chrome_sync_client.cc.orig	2016-05-11 19:02:15 UTC
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -554,7 +554,7 @@ void ChromeSyncClient::RegisterDesktopDa
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Dictionary sync is enabled by default.
   if (!disabled_types.Has(syncer::DICTIONARY)) {
     sync_service->RegisterDataTypeController(new UIDataTypeController(
