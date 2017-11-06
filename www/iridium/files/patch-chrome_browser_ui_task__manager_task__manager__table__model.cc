--- chrome/browser/ui/task_manager/task_manager_table_model.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/task_manager/task_manager_table_model.cc
@@ -454,13 +454,13 @@ base::string16 TaskManagerTableModel::Ge
           ? stringifier_->backgrounded_string()
           : stringifier_->foregrounded_string();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN: {
       const int fd_count = observed_task_manager()->GetOpenFdCount(tasks_[row]);
       return fd_count >= 0 ? base::FormatNumber(fd_count)
                            : stringifier_->n_a_string();
     }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
     case IDS_TASK_MANAGER_MEMORY_STATE_COLUMN: {
       return stringifier_->GetMemoryStateText(
@@ -623,7 +623,7 @@ int TaskManagerTableModel::CompareValues
       return BooleanCompare(is_proc1_bg, is_proc2_bg);
     }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN: {
       const int proc1_fd_count =
           observed_task_manager()->GetOpenFdCount(tasks_[row1]);
@@ -631,7 +631,7 @@ int TaskManagerTableModel::CompareValues
           observed_task_manager()->GetOpenFdCount(tasks_[row2]);
       return ValueCompare(proc1_fd_count, proc2_fd_count);
     }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
     default:
       NOTREACHED();
@@ -799,11 +799,11 @@ void TaskManagerTableModel::UpdateRefres
       type = REFRESH_TYPE_KEEPALIVE_COUNT;
       break;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN:
       type = REFRESH_TYPE_FD_COUNT;
       break;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
     default:
       NOTREACHED();
