--- chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.cc.orig	2026-01-16 14:21:21 UTC
+++ chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.cc
@@ -95,7 +95,7 @@ DialogText GetPromptDialogTextFromStatus(
       break;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           syncer::kReplaceSyncPromosWithSignInPromos) &&
       status.signin_status != collaboration::SigninStatus::kSigninDisabled) {
@@ -436,7 +436,7 @@ void CollaborationControllerDelegateDesktop::ShowError
       chrome::ShowBrowserModal(browser_, std::move(dialog_model));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void CollaborationControllerDelegateDesktop::
     MaybeShowSignInUiForHistorySyncOptin() {
   collaboration::ServiceStatus status = GetServiceStatus();
@@ -521,7 +521,7 @@ void CollaborationControllerDelegateDesktop::
   }
 
   AccountInfo account_for_promo =
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       signin_ui_util::GetSingleAccountForPromos(
           IdentityManagerFactory::GetForProfile(browser_->profile()));
 #else
@@ -556,7 +556,7 @@ void CollaborationControllerDelegateDesktop::
               .SetLabel(dialog_text.ok_button_text)
               .SetEnabled(true));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           syncer::kReplaceSyncPromosWithSignInPromos)) {
     dialog_builder.SetFootnote(ui::DialogModelLabel(dialog_text.footnote));
@@ -607,7 +607,7 @@ void CollaborationControllerDelegateDesktop::OnPromptD
         .Run(CollaborationControllerDelegate::Outcome::kSuccess);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           syncer::kReplaceSyncPromosWithSignInPromos)) {
     MaybeShowSignInUiForHistorySyncOptin();
