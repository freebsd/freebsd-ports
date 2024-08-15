--- components/password_manager/core/browser/password_manager_switches.h.orig	2024-07-30 11:12:21 UTC
+++ components/password_manager/core/browser/password_manager_switches.h
@@ -10,7 +10,7 @@
 
 namespace password_manager {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kPasswordStore[];
 extern const char kEnableEncryptionSelection[];
 #endif  // BUILDFLAG(IS_LINUX)
