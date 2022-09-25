--- content/browser/browser_child_process_host_impl.cc.orig	2022-09-24 10:57:32 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -307,6 +307,7 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
