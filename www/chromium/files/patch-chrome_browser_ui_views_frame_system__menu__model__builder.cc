--- chrome/browser/ui/views/frame/system_menu_model_builder.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/ui/views/frame/system_menu_model_builder.cc
@@ -77,7 +77,7 @@ void SystemMenuModelBuilder::BuildSystemMenuForBrowser
     ui::SimpleMenuModel* model) {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !BUILDFLAG(IS_CHROMEOS_LACROS)
   model->AddItemWithStringId(IDC_MINIMIZE_WINDOW, IDS_MINIMIZE_WINDOW_MENU);
   model->AddItemWithStringId(IDC_MAXIMIZE_WINDOW, IDS_MAXIMIZE_WINDOW_MENU);
   model->AddItemWithStringId(IDC_RESTORE_WINDOW, IDS_RESTORE_WINDOW_MENU);
@@ -93,7 +93,7 @@ void SystemMenuModelBuilder::BuildSystemMenuForBrowser
   }
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !BUILDFLAG(IS_CHROMEOS_LACROS)
   model->AddSeparator(ui::NORMAL_SEPARATOR);
   bool supports_server_side_decorations = true;
 #if defined(USE_OZONE) && \
@@ -148,7 +148,7 @@ void SystemMenuModelBuilder::BuildSystemMenuForAppOrPo
   }
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   model->AddSeparator(ui::NORMAL_SEPARATOR);
   model->AddItemWithStringId(IDC_CLOSE_WINDOW, IDS_CLOSE);
 #endif
