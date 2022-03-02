--- content/browser/browser_child_process_host_impl.cc.orig	2022-02-28 16:54:41 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -293,6 +293,7 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
