--- chrome/browser/task_manager/sampling/task_manager_impl.cc.orig	2021-04-14 18:40:55 UTC
+++ chrome/browser/task_manager/sampling/task_manager_impl.cc
@@ -222,11 +222,11 @@ void TaskManagerImpl::GetUSERHandles(TaskId task_id,
 }
 
 int TaskManagerImpl::GetOpenFdCount(TaskId task_id) const {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   return GetTaskGroupByTaskId(task_id)->open_fd_count();
 #else
   return -1;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
 }
 
 bool TaskManagerImpl::IsTaskOnBackgroundedProcess(TaskId task_id) const {
