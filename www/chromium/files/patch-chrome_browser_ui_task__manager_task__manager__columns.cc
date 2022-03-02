--- chrome/browser/ui/task_manager/task_manager_columns.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/ui/task_manager/task_manager_columns.cc
@@ -94,7 +94,7 @@ const TableColumnData kColumns[] = {
      base::size("100000") * kCharWidth, -1, true, false, false},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN, ui::TableColumn::RIGHT, -1, 0,
      base::size("999") * kCharWidth, -1, true, false, false},
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
