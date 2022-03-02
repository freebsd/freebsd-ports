--- sandbox/policy/features.cc.orig	2022-02-28 16:54:41 UTC
+++ sandbox/policy/features.cc
@@ -16,7 +16,11 @@ namespace features {
 // Enables network service sandbox.
 // (Only causes an effect when feature kNetworkService is enabled.)
 const base::Feature kNetworkServiceSandbox{"NetworkServiceSandbox",
+#if BUILDFLAG(IS_BSD)
+                                           base::FEATURE_ENABLED_BY_DEFAULT};
+#else
                                            base::FEATURE_DISABLED_BY_DEFAULT};
+#endif
 #endif  // !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN)
