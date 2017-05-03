--- chrome/browser/ui/task_manager/task_manager_columns.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/task_manager/task_manager_columns.cc
@@ -80,10 +80,10 @@ const TableColumnData kColumns[] = {
     {IDS_TASK_MANAGER_IDLE_WAKEUPS_COLUMN, ui::TableColumn::RIGHT, -1, 0,
      arraysize("idlewakeups") * kCharWidth, -1, true, false, false},
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     {IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN, ui::TableColumn::RIGHT, -1, 0,
      arraysize("999") * kCharWidth, -1, true, false, false},
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
     {IDS_TASK_MANAGER_PROCESS_PRIORITY_COLUMN, ui::TableColumn::LEFT, -1, 0,
      arraysize("background") * kCharWidth, -1, true, true, false},
     {IDS_TASK_MANAGER_MEMORY_STATE_COLUMN, ui::TableColumn::LEFT, -1, 0,
