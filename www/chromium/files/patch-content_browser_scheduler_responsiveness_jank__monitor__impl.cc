--- content/browser/scheduler/responsiveness/jank_monitor_impl.cc.orig	2020-11-16 14:34:07 UTC
+++ content/browser/scheduler/responsiveness/jank_monitor_impl.cc
@@ -332,7 +332,7 @@ void JankMonitorImpl::ThreadExecutionState::DidRunTask
     // in context menus, among others). Simply ignore the mismatches for now.
     // See https://crbug.com/929813 for the details of why the mismatch
     // happens.
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX) && defined(USE_OZONE)
+#if !defined(OS_CHROMEOS) && (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
     task_execution_metadata_.clear();
 #endif
     return;
