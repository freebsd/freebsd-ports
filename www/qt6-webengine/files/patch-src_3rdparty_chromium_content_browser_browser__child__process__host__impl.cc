--- src/3rdparty/chromium/content/browser/browser_child_process_host_impl.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/content/browser/browser_child_process_host_impl.cc
@@ -292,6 +292,7 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
