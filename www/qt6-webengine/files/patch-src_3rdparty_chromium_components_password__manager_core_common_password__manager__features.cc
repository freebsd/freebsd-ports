--- src/3rdparty/chromium/components/password_manager/core/common/password_manager_features.cc.orig	2023-10-27 05:38:38 UTC
+++ src/3rdparty/chromium/components/password_manager/core/common/password_manager_features.cc
@@ -18,7 +18,7 @@ BASE_FEATURE(kEnableOverwritingPlaceholderUsernames,
              "EnableOverwritingPlaceholderUsernames",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, initial sync will be forced during startup if the password
 // store has encryption service failures.
 BASE_FEATURE(kForceInitialSyncWhenDecryptionFails,
