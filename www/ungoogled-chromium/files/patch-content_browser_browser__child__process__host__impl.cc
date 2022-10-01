--- content/browser/browser_child_process_host_impl.cc.orig	2022-10-01 07:40:07 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -307,6 +307,7 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
