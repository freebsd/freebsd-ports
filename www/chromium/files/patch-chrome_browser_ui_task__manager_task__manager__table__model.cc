--- chrome/browser/ui/task_manager/task_manager_table_model.cc.orig	2017-02-02 02:02:50 UTC
+++ chrome/browser/ui/task_manager/task_manager_table_model.cc
@@ -390,13 +390,13 @@ base::string16 TaskManagerTableModel::Ge
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
 
     default:
       NOTREACHED();
@@ -540,7 +540,7 @@ int TaskManagerTableModel::CompareValues
       return BooleanCompare(is_proc1_bg, is_proc2_bg);
     }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN: {
       const int proc1_fd_count =
           observed_task_manager()->GetOpenFdCount(tasks_[row1]);
@@ -548,7 +548,7 @@ int TaskManagerTableModel::CompareValues
           observed_task_manager()->GetOpenFdCount(tasks_[row2]);
       return ValueCompare(proc1_fd_count, proc2_fd_count);
     }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
     default:
       NOTREACHED();
@@ -699,11 +699,11 @@ void TaskManagerTableModel::UpdateRefres
       type = REFRESH_TYPE_PRIORITY;
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
