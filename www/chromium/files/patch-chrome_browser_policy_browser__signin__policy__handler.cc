--- chrome/browser/policy/browser_signin_policy_handler.cc.orig	2021-07-19 18:45:09 UTC
+++ chrome/browser/policy/browser_signin_policy_handler.cc
@@ -52,7 +52,7 @@ void BrowserSigninPolicyHandler::ApplyPolicySettings(c
     }
     switch (static_cast<BrowserSigninMode>(value->GetInt())) {
       case BrowserSigninMode::kForced:
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
         prefs->SetValue(prefs::kForceBrowserSignin, base::Value(true));
 #endif
         FALLTHROUGH;
