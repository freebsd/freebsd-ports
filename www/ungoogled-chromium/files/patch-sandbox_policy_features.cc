--- sandbox/policy/features.cc.orig	2025-11-01 06:40:37 UTC
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
