--- content/browser/browser_child_process_host_impl.cc.orig	2022-03-28 18:11:04 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -293,6 +293,8 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
+      switches::kTrk,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
