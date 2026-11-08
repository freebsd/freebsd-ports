--- chrome/browser/ui/toolbar/app_menu_model.cc.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/ui/toolbar/app_menu_model.cc
@@ -251,7 +251,7 @@ std::u16string GetUpgradeDialogTitleText() {
     return l10n_util::GetStringUTF16(IDS_UPGRADE_BUBBLE_MENU_ITEM);
   }
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   return l10n_util::GetStringUTF16(IDS_RELAUNCH_TO_UPDATE_ALT);
 #else
   return l10n_util::GetStringUTF16(IDS_RELAUNCH_TO_UPDATE);
@@ -2208,7 +2208,7 @@ void AppMenuModel::Build() {
 
     SetAccessibleNameAt(GetIndexOfCommandId(IDC_SHOW_MANAGEMENT_PAGE).value(),
                         GetManagedUiMenuItemTooltip(browser_->profile()));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (enterprise_util::IsBrowserManaged(browser_->profile()) &&
         base::FeatureList::IsEnabled(features::kEnterpriseReleaseNotes)) {
       AddItemWithStringIdAndVectorIcon(
