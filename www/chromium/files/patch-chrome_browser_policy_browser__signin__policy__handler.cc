--- chrome/browser/policy/browser_signin_policy_handler.cc.orig	2021-04-14 18:40:54 UTC
+++ chrome/browser/policy/browser_signin_policy_handler.cc
@@ -52,7 +52,7 @@ void BrowserSigninPolicyHandler::ApplyPolicySettings(c
     }
     switch (static_cast<BrowserSigninMode>(int_value)) {
       case BrowserSigninMode::kForced:
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
         prefs->SetValue(prefs::kForceBrowserSignin, base::Value(true));
 #endif
         FALLTHROUGH;
