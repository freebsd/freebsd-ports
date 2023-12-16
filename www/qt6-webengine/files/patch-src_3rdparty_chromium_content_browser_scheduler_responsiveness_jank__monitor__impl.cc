--- src/3rdparty/chromium/content/browser/scheduler/responsiveness/jank_monitor_impl.cc.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/content/browser/scheduler/responsiveness/jank_monitor_impl.cc
@@ -334,7 +334,7 @@ void JankMonitorImpl::ThreadExecutionState::DidRunTask
     // in context menus, among others). Simply ignore the mismatches for now.
     // See https://crbug.com/929813 for the details of why the mismatch
     // happens.
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(IS_OZONE)
     task_execution_metadata_.clear();
 #endif
