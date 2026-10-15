--- components/webauthn/core/browser/gpm_user_verification_policy.cc.orig	2026-01-14 08:33:23 UTC
+++ components/webauthn/core/browser/gpm_user_verification_policy.cc
@@ -17,7 +17,7 @@ bool GpmWillDoUserVerification(device::UserVerificatio
     case device::UserVerificationRequirement::kPreferred:
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_IOS)
       return platform_has_biometrics;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return false;
 #else
       // This default is for unit tests.
