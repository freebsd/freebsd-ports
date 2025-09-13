--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc
@@ -63,14 +63,14 @@
 #include "chrome/browser/ui/webui/signin/signout_confirmation/signout_confirmation_ui.h"
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/signin/history_sync_optin/history_sync_optin_ui.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 namespace {
 
 const int kModalDialogWidth = 448;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const int kManagedUserNoticeConfirmationDialogWidth = 780;
 const int kManagedUserNoticeConfirmationDialogHeight = 560;
 #endif
@@ -137,7 +137,7 @@ SigninViewControllerDelegateViews::CreateSyncConfirmat
       kSyncConfirmationDialogWidth, InitializeSigninWebDialogUI(true));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::unique_ptr<views::WebView>
 SigninViewControllerDelegateViews::CreateHistorySyncOptInWebView(
     Browser* browser,
@@ -227,7 +227,7 @@ SigninViewControllerDelegateViews::CreateSignoutConfir
 }
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 std::unique_ptr<views::WebView>
 SigninViewControllerDelegateViews::CreateManagedUserNoticeConfirmationWebView(
@@ -402,7 +402,7 @@ SigninViewControllerDelegateViews::SigninViewControlle
 
   SetButtons(static_cast<int>(ui::mojom::DialogButton::kNone));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On the local profile creation dialog, cancelling the dialog (for instance
   // through the VKEY_ESCAPE accelerator) should delete the profile.
   if (delete_profile_on_cancel) {
@@ -494,7 +494,7 @@ void SigninViewControllerDelegateViews::DisplayModal()
   content_view_->RequestFocus();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SigninViewControllerDelegateViews::DeleteProfileOnCancel() {
   ProfileAttributesEntry* entry =
       g_browser_process->profile_manager()
@@ -534,7 +534,7 @@ SigninViewControllerDelegate::CreateSyncConfirmationDe
       /*animate_on_resize=*/true);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 SigninViewControllerDelegate*
 SigninViewControllerDelegate::CreateSyncHistoryOptInDelegate(
@@ -591,7 +591,7 @@ SigninViewControllerDelegate::CreateSignoutConfirmatio
 }
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 SigninViewControllerDelegate*
 SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
