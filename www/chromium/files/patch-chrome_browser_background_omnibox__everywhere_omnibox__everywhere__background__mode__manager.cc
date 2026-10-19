--- chrome/browser/background/omnibox_everywhere/omnibox_everywhere_background_mode_manager.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/background/omnibox_everywhere/omnibox_everywhere_background_mode_manager.cc
@@ -252,7 +252,7 @@ void OmniboxEverywhereBackgroundModeManager::OnBrowser
 
 void OmniboxEverywhereBackgroundModeManager::
     UpdateVisibilityOfExitInContextMenu() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (context_menu_) {
     const bool is_visible = GlobalBrowserCollection::GetInstance()->IsEmpty();
     const std::optional<size_t> index = context_menu_->GetIndexOfCommandId(
@@ -306,7 +306,7 @@ void OmniboxEverywhereBackgroundModeManager::UpdateSta
                 l10n_util::GetStringUTF16(
                     IDS_OMNIBOX_EVERYWHERE_STATUS_ICON_MENU_SETTINGS));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   menu->AddSeparator(ui::NORMAL_SEPARATOR);
   menu->AddItem(
       IDC_OMNIBOX_EVERYWHERE_STATUS_ICON_MENU_EXIT,
