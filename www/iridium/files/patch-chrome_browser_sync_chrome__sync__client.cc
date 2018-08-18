--- chrome/browser/sync/chrome_sync_client.cc.orig	2017-12-15 02:04:10.000000000 +0100
+++ chrome/browser/sync/chrome_sync_client.cc	2017-12-24 02:09:05.300500000 +0100
@@ -668,7 +668,7 @@
   }
 #endif  // BUILDFLAG(ENABLE_APP_LIST)
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // Dictionary sync is enabled by default.
   if (!disabled_types.Has(syncer::DICTIONARY)) {
     sync_service->RegisterDataTypeController(
@@ -676,7 +676,7 @@
             syncer::DICTIONARY, error_callback, this, syncer::GROUP_UI,
             BrowserThread::GetTaskRunnerForThread(BrowserThread::UI)));
   }
-#endif  // defined(OS_LINUX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_SUPERVISED_USERS)
   sync_service->RegisterDataTypeController(
