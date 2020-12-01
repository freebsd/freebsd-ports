--- chrome/browser/task_manager/sampling/task_group_sampler.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/task_manager/sampling/task_group_sampler.cc
@@ -43,9 +43,9 @@ TaskGroupSampler::TaskGroupSampler(
     const OnCpuRefreshCallback& on_cpu_refresh,
     const OnSwappedMemRefreshCallback& on_swapped_mem_refresh,
     const OnIdleWakeupsCallback& on_idle_wakeups,
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
     const OnOpenFdCountCallback& on_open_fd_count,
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
     const OnProcessPriorityCallback& on_process_priority)
     : process_(std::move(process)),
       process_metrics_(CreateProcessMetrics(process_.Handle())),
@@ -53,9 +53,9 @@ TaskGroupSampler::TaskGroupSampler(
       on_cpu_refresh_callback_(on_cpu_refresh),
       on_swapped_mem_refresh_callback_(on_swapped_mem_refresh),
       on_idle_wakeups_callback_(on_idle_wakeups),
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
       on_open_fd_count_callback_(on_open_fd_count),
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
       on_process_priority_callback_(on_process_priority) {
   DCHECK(blocking_pool_runner.get());
 
@@ -85,7 +85,7 @@ void TaskGroupSampler::Refresh(int64_t refresh_flags) 
         base::BindOnce(on_swapped_mem_refresh_callback_));
   }
 
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (TaskManagerObserver::IsResourceRefreshEnabled(REFRESH_TYPE_IDLE_WAKEUPS,
                                                     refresh_flags)) {
     base::PostTaskAndReplyWithResult(
@@ -93,9 +93,9 @@ void TaskGroupSampler::Refresh(int64_t refresh_flags) 
         base::BindOnce(&TaskGroupSampler::RefreshIdleWakeupsPerSecond, this),
         base::BindOnce(on_idle_wakeups_callback_));
   }
-#endif  // defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   if (TaskManagerObserver::IsResourceRefreshEnabled(REFRESH_TYPE_FD_COUNT,
                                                     refresh_flags)) {
     base::PostTaskAndReplyWithResult(
@@ -103,7 +103,7 @@ void TaskGroupSampler::Refresh(int64_t refresh_flags) 
         base::BindOnce(&TaskGroupSampler::RefreshOpenFdCount, this),
         base::BindOnce(on_open_fd_count_callback_));
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
 
   if (TaskManagerObserver::IsResourceRefreshEnabled(REFRESH_TYPE_PRIORITY,
                                                     refresh_flags)) {
@@ -145,13 +145,13 @@ int TaskGroupSampler::RefreshIdleWakeupsPerSecond() {
   return process_metrics_->GetIdleWakeupsPerSecond();
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
 int TaskGroupSampler::RefreshOpenFdCount() {
   DCHECK(worker_pool_sequenced_checker_.CalledOnValidSequence());
 
   return process_metrics_->GetOpenFdCount();
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
 
 bool TaskGroupSampler::RefreshProcessPriority() {
   DCHECK(worker_pool_sequenced_checker_.CalledOnValidSequence());
