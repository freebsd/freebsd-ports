--- sandbox/policy/features.cc.orig	2026-06-05 13:45:06 UTC
+++ sandbox/policy/features.cc
@@ -17,7 +17,11 @@ namespace sandbox::policy::features {
 #if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_FUCHSIA)
 // Enables network service sandbox.
 // (Only causes an effect when feature kNetworkServiceInProcess is disabled.)
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kNetworkServiceSandbox, base::FEATURE_ENABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kNetworkServiceSandbox, base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 // Enables a fine-grained seccomp-BPF syscall filter for the network service.
@@ -110,7 +114,7 @@ BASE_FEATURE(kWinSboxModuleTamperingProtection,
 BASE_FEATURE(kSpectreVariant2Mitigation, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Increase the renderer sandbox memory limit. As of 2023, there are no limits
 // on macOS, and a 1TiB limit on Windows. There are reports of users bumping
 // into the limit. This increases the limit by 2x compared to the default
