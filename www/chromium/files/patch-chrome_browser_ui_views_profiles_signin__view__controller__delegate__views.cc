--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc
@@ -63,7 +63,7 @@
 #include "chrome/browser/ui/webui/signin/signout_confirmation/signout_confirmation_ui.h"
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/signin/history_sync_optin/history_sync_optin_ui.h"
 #include "chrome/browser/ui/webui/signin/managed_user_profile_notice_ui.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
@@ -71,7 +71,7 @@
 namespace {
 
 const int kModalDialogWidth = 448;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const int kManagedUserNoticeConfirmationDialogWidth = 780;
 const int kManagedUserNoticeConfirmationDialogHeight = 560;
 #endif
@@ -142,7 +142,7 @@ SigninViewControllerDelegateViews::CreateSyncConfirmat
       kSyncConfirmationDialogWidth, InitializeSigninWebDialogUI(true));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::unique_ptr<views::WebView>
 SigninViewControllerDelegateViews::CreateHistorySyncOptInWebView(
     BrowserWindowInterface* browser,
@@ -251,7 +251,7 @@ SigninViewControllerDelegateViews::CreateSignoutConfir
 }
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 std::unique_ptr<views::WebView>
 SigninViewControllerDelegateViews::CreateManagedUserNoticeConfirmationWebView(
@@ -440,7 +440,7 @@ SigninViewControllerDelegateViews::SigninViewControlle
 
   SetButtons(static_cast<int>(ui::mojom::DialogButton::kNone));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On the local profile creation dialog, cancelling the dialog (for instance
   // through the VKEY_ESCAPE accelerator) should delete the profile.
   if (delete_profile_on_cancel) {
@@ -559,7 +559,7 @@ void SigninViewControllerDelegateViews::DetachFromWebC
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SigninViewControllerDelegateViews::DeleteProfileOnCancel() {
   ProfileAttributesEntry* entry =
       g_browser_process->profile_manager()
@@ -597,7 +597,7 @@ SigninViewControllerDelegate::CreateSyncConfirmationDe
       /*animate_on_resize=*/true);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 SigninViewControllerDelegate*
 SigninViewControllerDelegate::CreateSyncHistoryOptInDelegate(
@@ -660,7 +660,7 @@ SigninViewControllerDelegate::CreateSignoutConfirmatio
 }
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 SigninViewControllerDelegate*
 SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
