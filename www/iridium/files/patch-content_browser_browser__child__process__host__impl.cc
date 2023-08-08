--- content/browser/browser_child_process_host_impl.cc.orig	2023-07-24 14:27:53 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -321,6 +321,8 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
+      switches::kTrk,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
