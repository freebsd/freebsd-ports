--- chrome/browser/sync/chrome_sync_client.cc.orig	2016-03-04 21:50:06.513829549 +0100
+++ chrome/browser/sync/chrome_sync_client.cc	2016-03-04 21:50:19.352828601 +0100
@@ -572,7 +572,7 @@
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Dictionary sync is enabled by default.
   if (!disabled_types.Has(syncer::DICTIONARY)) {
     sync_service->RegisterDataTypeController(new UIDataTypeController(
