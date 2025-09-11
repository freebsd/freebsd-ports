--- chrome/browser/signin/signin_util.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -340,7 +340,7 @@ std::string SignedInStateToString(SignedInState state)
   }
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool ShouldShowHistorySyncOptinScreen(Profile& profile) {
   if (GetSignedInState(IdentityManagerFactory::GetForProfile(&profile)) !=
       signin_util::SignedInState::kSignedIn) {
