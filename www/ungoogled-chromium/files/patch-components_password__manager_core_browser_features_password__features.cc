--- components/password_manager/core/browser/features/password_features.cc.orig	2024-08-26 14:40:28 UTC
+++ components/password_manager/core/browser/features/password_features.cc
@@ -41,7 +41,7 @@ BASE_FEATURE(kClearUndecryptablePasswords,
 BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
              "ClearUndecryptablePasswordsInSync",
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -90,7 +90,7 @@ BASE_FEATURE(kPasswordManualFallbackAvailable,
              "PasswordManualFallbackAvailable",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRestartToGainAccessToKeychain,
              "RestartToGainAccessToKeychain",
 #if BUILDFLAG(IS_MAC)
