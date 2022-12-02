--- content/browser/browser_child_process_host_impl.cc.orig	2022-12-02 17:56:32 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -316,6 +316,7 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
