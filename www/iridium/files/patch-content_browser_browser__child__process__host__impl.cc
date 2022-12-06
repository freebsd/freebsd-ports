--- content/browser/browser_child_process_host_impl.cc.orig	2022-12-06 08:09:13 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -316,6 +316,8 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
+      switches::kTrk,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
