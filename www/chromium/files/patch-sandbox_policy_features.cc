--- sandbox/policy/features.cc.orig	2022-02-07 13:39:41 UTC
+++ sandbox/policy/features.cc
@@ -16,7 +16,11 @@ namespace features {
 // Enables network service sandbox.
 // (Only causes an effect when feature kNetworkService is enabled.)
 const base::Feature kNetworkServiceSandbox{"NetworkServiceSandbox",
+#if defined(OS_BSD)
+                                           base::FEATURE_ENABLED_BY_DEFAULT};
+#else
                                            base::FEATURE_DISABLED_BY_DEFAULT};
+#endif
 #endif  // !defined(OS_MAC) && !defined(OS_FUCHSIA)
 
 #if defined(OS_WIN)
