--- chrome/browser/signin/signin_util.h.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/signin/signin_util.h
@@ -168,7 +168,7 @@ bool IsSigninPending(signin::IdentityManager* identity
 // Returns the current state of the primary account that is used in Chrome.
 SignedInState GetSignedInState(const signin::IdentityManager* identity_manager);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Returns if the necessary conditions to show the History Sync Optin screen
 // are met.
 // This method does not take into account any feature flags related to the above
