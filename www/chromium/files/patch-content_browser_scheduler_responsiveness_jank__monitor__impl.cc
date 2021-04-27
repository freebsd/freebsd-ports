--- content/browser/scheduler/responsiveness/jank_monitor_impl.cc.orig	2021-04-14 18:41:02 UTC
+++ content/browser/scheduler/responsiveness/jank_monitor_impl.cc
@@ -333,7 +333,7 @@ void JankMonitorImpl::ThreadExecutionState::DidRunTask
     // in context menus, among others). Simply ignore the mismatches for now.
     // See https://crbug.com/929813 for the details of why the mismatch
     // happens.
-#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) && defined(USE_OZONE)
     task_execution_metadata_.clear();
 #endif
     return;
