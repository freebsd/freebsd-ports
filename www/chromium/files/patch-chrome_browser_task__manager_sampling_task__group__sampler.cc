--- chrome/browser/task_manager/sampling/task_group_sampler.cc.orig	2019-06-04 18:55:18 UTC
+++ chrome/browser/task_manager/sampling/task_group_sampler.cc
@@ -43,9 +43,9 @@ TaskGroupSampler::TaskGroupSampler(
     const OnCpuRefreshCallback& on_cpu_refresh,
     const OnSwappedMemRefreshCallback& on_swapped_mem_refresh,
     const OnIdleWakeupsCallback& on_idle_wakeups,
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
     const OnOpenFdCountCallback& on_open_fd_count,
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
     const OnProcessPriorityCallback& on_process_priority)
     : process_(std::move(process)),
       process_metrics_(CreateProcessMetrics(process_.Handle())),
@@ -53,9 +53,9 @@ TaskGroupSampler::TaskGroupSampler(
       on_cpu_refresh_callback_(on_cpu_refresh),
       on_swapped_mem_refresh_callback_(on_swapped_mem_refresh),
       on_idle_wakeups_callback_(on_idle_wakeups),
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
       on_open_fd_count_callback_(on_open_fd_count),
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
       on_process_priority_callback_(on_process_priority) {
   DCHECK(blocking_pool_runner.get());
 
@@ -86,7 +86,7 @@ void TaskGroupSampler::Refresh(int64_t refresh_flags) 
         on_swapped_mem_refresh_callback_);
   }
 
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (TaskManagerObserver::IsResourceRefreshEnabled(REFRESH_TYPE_IDLE_WAKEUPS,
                                                     refresh_flags)) {
     base::PostTaskAndReplyWithResult(
@@ -95,9 +95,9 @@ void TaskGroupSampler::Refresh(int64_t refresh_flags) 
         base::Bind(&TaskGroupSampler::RefreshIdleWakeupsPerSecond, this),
         on_idle_wakeups_callback_);
   }
-#endif  // defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   if (TaskManagerObserver::IsResourceRefreshEnabled(REFRESH_TYPE_FD_COUNT,
                                                     refresh_flags)) {
     base::PostTaskAndReplyWithResult(
@@ -106,7 +106,7 @@ void TaskGroupSampler::Refresh(int64_t refresh_flags) 
         base::Bind(&TaskGroupSampler::RefreshOpenFdCount, this),
         on_open_fd_count_callback_);
   }
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 
   if (TaskManagerObserver::IsResourceRefreshEnabled(REFRESH_TYPE_PRIORITY,
                                                     refresh_flags)) {
@@ -151,13 +151,13 @@ int TaskGroupSampler::RefreshIdleWakeupsPerSecond() {
   return process_metrics_->GetIdleWakeupsPerSecond();
 }
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 int TaskGroupSampler::RefreshOpenFdCount() {
   DCHECK(worker_pool_sequenced_checker_.CalledOnValidSequence());
 
   return process_metrics_->GetOpenFdCount();
 }
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 
 bool TaskGroupSampler::RefreshProcessPriority() {
   DCHECK(worker_pool_sequenced_checker_.CalledOnValidSequence());
