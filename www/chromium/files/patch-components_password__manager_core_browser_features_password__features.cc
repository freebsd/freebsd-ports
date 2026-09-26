--- components/password_manager/core/browser/features/password_features.cc.orig	2026-09-25 15:26:43 UTC
+++ components/password_manager/core/browser/features/password_features.cc
@@ -76,7 +76,7 @@ BASE_FEATURE(kClearUndecryptablePasswords,
 BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
              "ClearUndecryptablePasswordsInSync",
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -189,7 +189,7 @@ BASE_FEATURE(kPreventPasswordManagerOnFederatedLogin,
 // Remove in or after M155.
 BASE_FEATURE(kRecordPasswordReadiness, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRestartToGainAccessToKeychain,
 #if BUILDFLAG(IS_MAC)
              base::FEATURE_ENABLED_BY_DEFAULT);
