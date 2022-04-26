--- content/browser/browser_child_process_host_impl.cc.orig	2022-04-01 07:48:30 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -292,6 +292,8 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
+      switches::kTrk,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
