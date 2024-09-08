--- sandbox/policy/features.h.orig	2024-08-26 14:40:28 UTC
+++ sandbox/policy/features.h
@@ -47,7 +47,7 @@ SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kSpectreVar
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kForceSpectreVariant2Mitigation);
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(
     kForceDisableSpectreVariant2MitigationInNetworkService);
 
