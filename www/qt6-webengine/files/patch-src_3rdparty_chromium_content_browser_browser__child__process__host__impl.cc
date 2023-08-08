--- src/3rdparty/chromium/content/browser/browser_child_process_host_impl.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/content/browser/browser_child_process_host_impl.cc
@@ -316,6 +316,7 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
