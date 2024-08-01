--- components/password_manager/core/browser/features/password_features.cc.orig	2024-08-01 05:47:53 UTC
+++ components/password_manager/core/browser/features/password_features.cc
@@ -33,7 +33,7 @@ BASE_FEATURE(kBiometricTouchToFill,
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS)  // Desktop
 BASE_FEATURE(kButterOnDesktopFollowup,
              "ButterOnDesktopFollowup",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -47,7 +47,7 @@ BASE_FEATURE(kClearUndecryptablePasswords,
 BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
              "ClearUndecryptablePasswordsInSync",
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -109,7 +109,7 @@ BASE_FEATURE(kPasswordManualFallbackAvailable,
              "PasswordManualFallbackAvailable",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRestartToGainAccessToKeychain,
              "RestartToGainAccessToKeychain",
 #if BUILDFLAG(IS_MAC)
