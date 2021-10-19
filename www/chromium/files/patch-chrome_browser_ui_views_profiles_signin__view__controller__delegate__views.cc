--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc.orig	2021-09-24 18:32:11 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc
@@ -83,7 +83,7 @@ SigninViewControllerDelegateViews::CreateReauthConfirm
                              kReauthDialogHeight, kReauthDialogWidth);
 }
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
 // static
 std::unique_ptr<views::WebView>
@@ -345,7 +345,7 @@ SigninViewControllerDelegate::CreateReauthConfirmation
       browser, ui::MODAL_TYPE_CHILD, false, true);
 }
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
 // static
 SigninViewControllerDelegate*
