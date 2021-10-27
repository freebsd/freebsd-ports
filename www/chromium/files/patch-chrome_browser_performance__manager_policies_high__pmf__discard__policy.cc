--- chrome/browser/performance_manager/policies/high_pmf_discard_policy.cc.orig	2021-09-24 18:27:13 UTC
+++ chrome/browser/performance_manager/policies/high_pmf_discard_policy.cc
@@ -17,7 +17,7 @@
 #include "content/public/browser/browser_task_traits.h"
 #include "content/public/browser/browser_thread.h"
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 #include "base/memory/memory_pressure_monitor.h"
 #endif
 
@@ -122,7 +122,7 @@ void HighPMFDiscardPolicy::OnProcessMemoryMetricsAvail
 
   if (should_discard) {
     discard_attempt_in_progress_ = true;
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
     // Record the memory pressure level before discarding a tab.
     content::GetUIThreadTaskRunner({})->PostTask(
         FROM_HERE, base::BindOnce([]() {
