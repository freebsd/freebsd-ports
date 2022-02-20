--- chrome/browser/ui/task_manager/task_manager_columns.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/ui/task_manager/task_manager_columns.cc
@@ -94,7 +94,7 @@ const TableColumnData kColumns[] = {
      base::size("100000") * kCharWidth, -1, true, false, false},
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
     {IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN, ui::TableColumn::RIGHT, -1, 0,
      base::size("999") * kCharWidth, -1, true, false, false},
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
