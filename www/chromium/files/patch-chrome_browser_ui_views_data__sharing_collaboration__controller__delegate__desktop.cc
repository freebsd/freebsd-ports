--- chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.cc
@@ -99,7 +99,7 @@ DialogText GetPromptDialogTextFromStatus(
       break;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (syncer::IsReplaceSyncPromosWithSignInPromosEnabled() &&
       status.signin_status != collaboration::SigninStatus::kSigninDisabled) {
     title_id = IDS_SYNC_HISTORY_TITLE;
@@ -443,7 +443,7 @@ void CollaborationControllerDelegateDesktop::ShowError
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void CollaborationControllerDelegateDesktop::
     MaybeShowSignInUiForHistorySyncOptin() {
   collaboration::ServiceStatus status = GetServiceStatus();
@@ -529,7 +529,7 @@ void CollaborationControllerDelegateDesktop::
   }
 
   AccountInfo account_for_promo =
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       signin_ui_util::GetSingleAccountForPromos(
           IdentityManagerFactory::GetForProfile(browser_->GetProfile()),
           AccountPreviewDataServiceFactory::GetForProfile(
@@ -566,7 +566,7 @@ void CollaborationControllerDelegateDesktop::
               .SetLabel(dialog_text.ok_button_text)
               .SetEnabled(true));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (syncer::IsReplaceSyncPromosWithSignInPromosEnabled()) {
     dialog_builder.SetFootnote(ui::DialogModelLabel(dialog_text.footnote));
 
@@ -621,7 +621,7 @@ void CollaborationControllerDelegateDesktop::OnPromptD
         .Run(CollaborationControllerDelegate::Outcome::kSuccess);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (syncer::IsReplaceSyncPromosWithSignInPromosEnabled()) {
     MaybeShowSignInUiForHistorySyncOptin();
     return;
