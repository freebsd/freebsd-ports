--- chrome/browser/task_manager/sampling/task_group_sampler.h.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/task_manager/sampling/task_group_sampler.h
@@ -45,9 +45,9 @@ class TaskGroupSampler : public base::RefCountedThread
   using OnCpuRefreshCallback = base::Callback<void(double)>;
   using OnMemoryRefreshCallback = base::Callback<void(MemoryUsageStats)>;
   using OnIdleWakeupsCallback = base::Callback<void(int)>;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   using OnOpenFdCountCallback = base::Callback<void(int)>;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   using OnProcessPriorityCallback = base::Callback<void(bool)>;
 
   TaskGroupSampler(
@@ -56,9 +56,9 @@ class TaskGroupSampler : public base::RefCountedThread
       const OnCpuRefreshCallback& on_cpu_refresh,
       const OnMemoryRefreshCallback& on_memory_refresh,
       const OnIdleWakeupsCallback& on_idle_wakeups,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       const OnOpenFdCountCallback& on_open_fd_count,
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
       const OnProcessPriorityCallback& on_process_priority);
 
   // Refreshes the expensive process' stats (CPU usage, memory usage, and idle
@@ -73,9 +73,9 @@ class TaskGroupSampler : public base::RefCountedThread
   double RefreshCpuUsage();
   MemoryUsageStats RefreshMemoryUsage();
   int RefreshIdleWakeupsPerSecond();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int RefreshOpenFdCount();
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   bool RefreshProcessPriority();
 
   // The process that holds the handle that we own so that we can use it for
@@ -93,9 +93,9 @@ class TaskGroupSampler : public base::RefCountedThread
   const OnCpuRefreshCallback on_cpu_refresh_callback_;
   const OnMemoryRefreshCallback on_memory_refresh_callback_;
   const OnIdleWakeupsCallback on_idle_wakeups_callback_;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const OnOpenFdCountCallback on_open_fd_count_callback_;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   const OnProcessPriorityCallback on_process_priority_callback_;
 
   // To assert we're running on the correct thread.
