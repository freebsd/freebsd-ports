--- src/chrome/browser/ui/views/frame/system_menu_model_builder.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/views/frame/system_menu_model_builder.cc
@@ -139,7 +139,7 @@ void SystemMenuModelBuilder::BuildSystem
   }
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   AddItemWithIconMaybe(model, IDC_MINIMIZE_WINDOW, IDS_MINIMIZE_WINDOW_MENU,
                        views::kChromeMinimizeIcon);
   AddItemWithIconMaybe(model, IDC_MAXIMIZE_WINDOW, IDS_MAXIMIZE_WINDOW_MENU,
@@ -268,7 +268,7 @@ void SystemMenuModelBuilder::BuildSystem
     model->AddItemWithStringId(IDC_TASK_MANAGER_CONTEXT_MENU,
                                task_manager_string_id);
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   model->AddSeparator(ui::NORMAL_SEPARATOR);
   bool supports_server_side_decorations = true;
 #if BUILDFLAG(IS_OZONE) && !BUILDFLAG(IS_CHROMEOS)
@@ -361,7 +361,7 @@ void SystemMenuModelBuilder::BuildSystem
 #endif
     model->AddItemWithStringId(IDC_TASK_MANAGER, task_manager_string_id);
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   model->AddSeparator(ui::NORMAL_SEPARATOR);
   model->AddItemWithStringId(IDC_CLOSE_WINDOW, IDS_CLOSE);
 #endif
