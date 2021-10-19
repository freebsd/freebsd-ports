--- components/startup_metric_utils/browser/startup_metric_utils.cc.orig	2021-09-24 04:26:04 UTC
+++ components/startup_metric_utils/browser/startup_metric_utils.cc
@@ -344,7 +344,7 @@ base::TimeTicks StartupTimeToTimeTicks(base::Time time
 
 // Enabling this logic on OS X causes a significant performance regression.
 // https://crbug.com/601270
-#if !defined(OS_APPLE)
+#if !defined(OS_APPLE) && !defined(OS_BSD)
   static bool statics_initialized = false;
 
   base::ThreadPriority previous_priority = base::ThreadPriority::NORMAL;
@@ -358,7 +358,7 @@ base::TimeTicks StartupTimeToTimeTicks(base::Time time
   static const base::Time time_base = base::Time::Now();
   static const base::TimeTicks trace_ticks_base = base::TimeTicks::Now();
 
-#if !defined(OS_APPLE)
+#if !defined(OS_APPLE) && !defined(OS_BSD)
   if (!statics_initialized) {
     base::PlatformThread::SetCurrentThreadPriority(previous_priority);
   }
