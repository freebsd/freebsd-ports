--- components/password_manager/core/browser/features/password_features.cc.orig	2026-07-01 06:24:19 UTC
+++ components/password_manager/core/browser/features/password_features.cc
@@ -78,7 +78,7 @@ BASE_FEATURE(kClearUndecryptablePasswords,
 BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
              "ClearUndecryptablePasswordsInSync",
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -115,7 +115,7 @@ BASE_FEATURE(kFetchChangePasswordUrlForPasswordChange,
 BASE_FEATURE(kFillOnAccountSelect,
              "fill-on-account-select",
 // TODO(504600482): Disable the feature again upon fixing the bug.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -181,7 +181,7 @@ BASE_FEATURE(kPasswordStorePropagatesActionableErrors,
 
 BASE_FEATURE(kPasswordCheckupPrototype, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRestartToGainAccessToKeychain,
 #if BUILDFLAG(IS_MAC)
              base::FEATURE_ENABLED_BY_DEFAULT);
