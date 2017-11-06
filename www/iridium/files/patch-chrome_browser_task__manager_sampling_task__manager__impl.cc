--- chrome/browser/task_manager/sampling/task_manager_impl.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/task_manager/sampling/task_manager_impl.cc
@@ -180,11 +180,11 @@ void TaskManagerImpl::GetUSERHandles(Tas
 }
 
 int TaskManagerImpl::GetOpenFdCount(TaskId task_id) const {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return GetTaskGroupByTaskId(task_id)->open_fd_count();
 #else
   return -1;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 bool TaskManagerImpl::IsTaskOnBackgroundedProcess(TaskId task_id) const {
