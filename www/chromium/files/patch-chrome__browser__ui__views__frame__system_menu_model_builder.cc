--- chrome/browser/ui/views/frame/system_menu_model_builder.cc.orig	2015-04-14 18:18:50.000000000 -0400
+++ chrome/browser/ui/views/frame/system_menu_model_builder.cc	2015-04-28 09:50:22.925763000 -0400
@@ -65,7 +65,7 @@
     model->AddSeparator(ui::NORMAL_SEPARATOR);
     model->AddItemWithStringId(IDC_TASK_MANAGER, IDS_TASK_MANAGER);
   }
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   model->AddSeparator(ui::NORMAL_SEPARATOR);
   model->AddCheckItemWithStringId(IDC_USE_SYSTEM_TITLE_BAR,
                                   IDS_SHOW_WINDOW_DECORATIONS_MENU);
@@ -103,7 +103,7 @@
     model->AddSeparator(ui::NORMAL_SEPARATOR);
     model->AddItemWithStringId(IDC_TASK_MANAGER, IDS_TASK_MANAGER);
   }
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   model->AddSeparator(ui::NORMAL_SEPARATOR);
   model->AddItemWithStringId(IDC_CLOSE_WINDOW, IDS_CLOSE);
 #endif
