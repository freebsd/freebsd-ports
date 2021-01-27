--- chrome/browser/performance_manager/policies/policy_features.cc.orig	2021-01-19 11:25:47 UTC
+++ chrome/browser/performance_manager/policies/policy_features.cc
@@ -125,7 +125,7 @@ const base::Feature kPageFreezingFromPerformanceManage
 
 const base::Feature kUrgentDiscardingFromPerformanceManager{
   "UrgentDiscardingFromPerformanceManager",
-#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
