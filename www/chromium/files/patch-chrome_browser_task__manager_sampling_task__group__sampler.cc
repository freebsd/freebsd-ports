--- chrome/browser/task_manager/sampling/task_group_sampler.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/task_manager/sampling/task_group_sampler.cc
@@ -36,9 +36,9 @@ TaskGroupSampler::TaskGroupSampler(
     const OnCpuRefreshCallback& on_cpu_refresh,
     const OnMemoryRefreshCallback& on_memory_refresh,
     const OnIdleWakeupsCallback& on_idle_wakeups,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     const OnOpenFdCountCallback& on_open_fd_count,
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
     const OnProcessPriorityCallback& on_process_priority)
     : process_(std::move(process)),
       process_metrics_(CreateProcessMetrics(process_.Handle())),
@@ -46,9 +46,9 @@ TaskGroupSampler::TaskGroupSampler(
       on_cpu_refresh_callback_(on_cpu_refresh),
       on_memory_refresh_callback_(on_memory_refresh),
       on_idle_wakeups_callback_(on_idle_wakeups),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       on_open_fd_count_callback_(on_open_fd_count),
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
       on_process_priority_callback_(on_process_priority) {
   DCHECK(blocking_pool_runner.get());
 
@@ -80,7 +80,7 @@ void TaskGroupSampler::Refresh(int64_t r
         on_memory_refresh_callback_);
   }
 
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (TaskManagerObserver::IsResourceRefreshEnabled(REFRESH_TYPE_IDLE_WAKEUPS,
                                                     refresh_flags)) {
     base::PostTaskAndReplyWithResult(
@@ -89,7 +89,7 @@ void TaskGroupSampler::Refresh(int64_t r
         base::Bind(&TaskGroupSampler::RefreshIdleWakeupsPerSecond, this),
         on_idle_wakeups_callback_);
   }
-#endif  // defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_LINUX)
   if (TaskManagerObserver::IsResourceRefreshEnabled(REFRESH_TYPE_FD_COUNT,
