--- chrome/browser/signin/signin_util.h.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/signin/signin_util.h
@@ -171,7 +171,7 @@ SignedInState GetSignedInState(const signin::IdentityM
 // Returns a string representation of `SignedInState`.
 std::string SignedInStateToString(SignedInState state);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Returns if the necessary conditions to show the History Sync Optin screen
 // are met.
 // This method does not take into account any feature flags related to the above
