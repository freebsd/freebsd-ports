--- components/performance_manager/features.cc.orig	2021-12-14 11:45:03 UTC
+++ components/performance_manager/features.cc
@@ -22,7 +22,7 @@ const base::Feature kUrgentDiscardingFromPerformanceMa
   "UrgentDiscardingFromPerformanceManager",
 // Ash Chrome uses memory pressure evaluator instead of performance manager to
 // discard tabs.
-#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
