--- components/performance_manager/features.cc.orig	2021-09-14 01:51:55 UTC
+++ components/performance_manager/features.cc
@@ -56,7 +56,7 @@ const base::Feature kUrgentDiscardingFromPerformanceMa
   "UrgentDiscardingFromPerformanceManager",
 // Chrome OS uses memory pressure evaluator instead of performance manager to
 // discard tabs.
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
