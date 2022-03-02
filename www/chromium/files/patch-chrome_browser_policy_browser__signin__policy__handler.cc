--- chrome/browser/policy/browser_signin_policy_handler.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/policy/browser_signin_policy_handler.cc
@@ -43,7 +43,7 @@ void BrowserSigninPolicyHandler::ApplyPolicySettings(c
   const base::Value* value = policies.GetValue(policy_name());
   switch (static_cast<BrowserSigninMode>(value->GetInt())) {
     case BrowserSigninMode::kForced:
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
       prefs->SetValue(prefs::kForceBrowserSignin, base::Value(true));
 #endif
       [[fallthrough]];
