--- content/browser/browser_child_process_host_impl.cc.orig	2022-10-05 07:34:01 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -307,6 +307,8 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
+      switches::kTrk,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
