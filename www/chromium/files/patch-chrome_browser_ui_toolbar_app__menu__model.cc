--- chrome/browser/ui/toolbar/app_menu_model.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/toolbar/app_menu_model.cc
@@ -197,7 +197,7 @@
 #include "content/public/browser/gpu_data_manager.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/global_features.h"
 #include "chrome/browser/lifetime/scheduled_restart_manager.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -1226,7 +1226,7 @@ std::u16string AppMenuModel::GetUpgradeDialogTitleText
     return l10n_util::GetStringUTF16(IDS_UPGRADE_BUBBLE_MENU_ITEM);
   }
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   return l10n_util::GetStringUTF16(IDS_RELAUNCH_TO_UPDATE_ALT);
 #else
   return l10n_util::GetStringUTF16(IDS_RELAUNCH_TO_UPDATE);
@@ -1236,7 +1236,7 @@ std::u16string AppMenuModel::GetUpgradeDialogTitleText
 // static
 std::u16string AppMenuModel::GetUpgradeDialogSubstringText() {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   if (!UpgradeDetector::GetInstance()->is_outdated_install() &&
       !UpgradeDetector::GetInstance()->is_outdated_install_no_au()) {
     return l10n_util::GetStringUTF16(IDS_RELAUNCH_TO_UPDATE_ALT_MINOR_TEXT);
@@ -1338,7 +1338,7 @@ void AppMenuModel::LogMenuMetrics(int command_id) {
       }
       LogMenuAction(MENU_ACTION_UPGRADE_DIALOG);
       break;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case IDC_SCHEDULED_RESTART_DIALOG:
       if (!uma_action_recorded_) {
         base::UmaHistogramMediumTimes(
@@ -2515,7 +2515,7 @@ void AppMenuModel::Build() {
 
     SetAccessibleNameAt(GetIndexOfCommandId(IDC_SHOW_MANAGEMENT_PAGE).value(),
                         GetManagedUiMenuItemTooltip(browser_->GetProfile()));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (enterprise_util::IsBrowserManaged(browser_->GetProfile()) &&
         base::FeatureList::IsEnabled(features::kEnterpriseReleaseNotes)) {
       AddItemWithStringIdAndVectorIcon(
@@ -2561,7 +2561,7 @@ void AppMenuModel::CreateZoomMenu() {
 }
 
 bool AppMenuModel::AddScheduledRestartMenuItem() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!scheduled_restart::ScheduledRestartManager::IsAppMenuItemEnabled() ||
       !g_browser_process || !g_browser_process->GetFeatures()) {
     return false;
