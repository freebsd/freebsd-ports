--- components/startup_metric_utils/browser/startup_metric_utils.cc.orig	2022-02-28 16:54:41 UTC
+++ components/startup_metric_utils/browser/startup_metric_utils.cc
@@ -347,7 +347,7 @@ base::TimeTicks StartupTimeToTimeTicks(base::Time time
 
 // Enabling this logic on OS X causes a significant performance regression.
 // https://crbug.com/601270
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   static bool statics_initialized = false;
 
   base::ThreadPriority previous_priority = base::ThreadPriority::NORMAL;
@@ -361,7 +361,7 @@ base::TimeTicks StartupTimeToTimeTicks(base::Time time
   static const base::Time time_base = base::Time::Now();
   static const base::TimeTicks trace_ticks_base = base::TimeTicks::Now();
 
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   if (!statics_initialized) {
     base::PlatformThread::SetCurrentThreadPriority(previous_priority);
   }
