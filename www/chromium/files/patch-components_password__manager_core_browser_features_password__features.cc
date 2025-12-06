--- components/password_manager/core/browser/features/password_features.cc.orig	2025-12-05 10:12:50 UTC
+++ components/password_manager/core/browser/features/password_features.cc
@@ -71,7 +71,7 @@ BASE_FEATURE(kClearUndecryptablePasswords,
 BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
              "ClearUndecryptablePasswordsInSync",
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -139,7 +139,7 @@ BASE_FEATURE(kPasswordManualFallbackAvailable,
 
 BASE_FEATURE(kPasswordManagerLogToTerminal, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRestartToGainAccessToKeychain,
 #if BUILDFLAG(IS_MAC)
              base::FEATURE_ENABLED_BY_DEFAULT);
