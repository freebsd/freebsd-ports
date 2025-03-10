--- src/3rdparty/chromium/components/password_manager/core/common/password_manager_features.h.orig	2023-12-10 06:10:27 UTC
+++ src/3rdparty/chromium/components/password_manager/core/common/password_manager_features.h
@@ -19,7 +19,7 @@ namespace password_manager::features {
 // alongside the definition of their values in the .cc file.
 BASE_DECLARE_FEATURE(kEnableOverwritingPlaceholderUsernames);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kForceInitialSyncWhenDecryptionFails);
 #endif
 BASE_DECLARE_FEATURE(kForgotPasswordFormSupport);
