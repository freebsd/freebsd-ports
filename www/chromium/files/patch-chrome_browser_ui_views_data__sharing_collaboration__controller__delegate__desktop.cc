--- chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.cc
@@ -97,7 +97,7 @@ DialogText GetPromptDialogTextFromStatus(
       break;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (syncer::IsReplaceSyncPromosWithSignInPromosEnabled() &&
       status.signin_status != collaboration::SigninStatus::kSigninDisabled) {
     title_id = IDS_SYNC_HISTORY_TITLE;
@@ -434,7 +434,7 @@ void CollaborationControllerDelegateDesktop::ShowError
       chrome::ShowBrowserModal(browser_, std::move(dialog_model));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void CollaborationControllerDelegateDesktop::
     MaybeShowSignInUiForHistorySyncOptin() {
   collaboration::ServiceStatus status = GetServiceStatus();
@@ -520,7 +520,7 @@ void CollaborationControllerDelegateDesktop::
   }
 
   AccountInfo account_for_promo =
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       signin_ui_util::GetSingleAccountForPromos(
           IdentityManagerFactory::GetForProfile(browser_->GetProfile()),
           AccountPreviewDataServiceFactory::GetForProfile(
@@ -557,7 +557,7 @@ void CollaborationControllerDelegateDesktop::
               .SetLabel(dialog_text.ok_button_text)
               .SetEnabled(true));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (syncer::IsReplaceSyncPromosWithSignInPromosEnabled()) {
     dialog_builder.SetFootnote(ui::DialogModelLabel(dialog_text.footnote));
 
@@ -606,7 +606,7 @@ void CollaborationControllerDelegateDesktop::OnPromptD
         .Run(CollaborationControllerDelegate::Outcome::kSuccess);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (syncer::IsReplaceSyncPromosWithSignInPromosEnabled()) {
     MaybeShowSignInUiForHistorySyncOptin();
     return;
