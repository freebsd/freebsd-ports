--- components/password_manager/core/browser/features/password_features.h.orig	2023-12-10 06:10:27 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -15,7 +15,7 @@ namespace password_manager::features {
 // All features in alphabetical order. The features should be documented
 // alongside the definition of their values in the .cc file.
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kAttachLogsToAutofillRaterExtensionReport);
 #endif
 
