--- chrome/browser/ui/views/app_menu/action_app_menu_manager.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/views/app_menu/action_app_menu_manager.cc
@@ -40,7 +40,7 @@
 #include "chrome/browser/ui/tabs/tab_strip_model.h"
 #include "ui/base/class_property.h"
 #include "ui/base/models/menu_separator_types.h"
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/global_features.h"
 #include "chrome/browser/lifetime/scheduled_restart_manager.h"
 #endif
@@ -552,7 +552,7 @@ void ActionAppMenuManager::AddNotificationActions(acti
                 kActionUpgradeDialog,
                 {.minor_text =
                      AppMenuModel::GetUpgradeDialogSubstringText()})) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           actions::ActionItem* scheduled_restart_action =
               actions::ActionManager::Get().FindAction(
                   kActionScheduledRestartDialog, scope);
