--- chrome/browser/task_manager/sampling/task_manager_impl.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/task_manager/sampling/task_manager_impl.cc
@@ -217,7 +217,7 @@ void TaskManagerImpl::GetUSERHandles(TaskId task_id,
 }
 
 int TaskManagerImpl::GetOpenFdCount(TaskId task_id) const {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   return GetTaskGroupByTaskId(task_id)->open_fd_count();
 #else
   return -1;
