--- components/performance_manager/features.cc.orig	2021-07-28 07:52:32 UTC
+++ components/performance_manager/features.cc
@@ -54,7 +54,7 @@ const base::Feature kRunOnMainThread{"RunOnMainThread"
 #if !defined(OS_ANDROID)
 const base::Feature kUrgentDiscardingFromPerformanceManager {
   "UrgentDiscardingFromPerformanceManager",
-#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
