--- chrome/browser/ui/signin/dice_web_signin_interceptor_delegate.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/ui/signin/dice_web_signin_interceptor_delegate.cc
@@ -59,7 +59,7 @@ class ForcedEnterpriseSigninInterceptionHandle
   void ShowEnterpriseProfileInterceptionDialog(const AccountInfo& account_info,
                                                SkColor profile_color) {
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
     if (base::FeatureList::IsEnabled(kAccountPoliciesLoadedWithoutSync)) {
       browser_->signin_view_controller()->ShowModalEnterpriseConfirmationDialog(
           account_info, profile_color,
