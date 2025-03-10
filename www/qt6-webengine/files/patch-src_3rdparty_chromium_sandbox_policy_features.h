--- src/3rdparty/chromium/sandbox/policy/features.h.orig	2024-01-30 07:53:34 UTC
+++ src/3rdparty/chromium/sandbox/policy/features.h
@@ -44,7 +44,7 @@ SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kSpectreVar
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kForceSpectreVariant2Mitigation);
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(
     kForceDisableSpectreVariant2MitigationInNetworkService);
 
