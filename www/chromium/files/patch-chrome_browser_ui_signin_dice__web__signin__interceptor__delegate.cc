--- chrome/browser/ui/signin/dice_web_signin_interceptor_delegate.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/ui/signin/dice_web_signin_interceptor_delegate.cc
@@ -66,7 +66,7 @@ class ForcedEnterpriseSigninInterceptionHandle
   void ShowEnterpriseProfileInterceptionDialog(const AccountInfo& account_info,
                                                SkColor profile_color) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(kAccountPoliciesLoadedWithoutSync)) {
       browser_->signin_view_controller()->ShowModalEnterpriseConfirmationDialog(
           account_info, profile_color,
