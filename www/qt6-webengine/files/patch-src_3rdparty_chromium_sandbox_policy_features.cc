--- src/3rdparty/chromium/sandbox/policy/features.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/sandbox/policy/features.cc
@@ -14,7 +14,11 @@ const base::Feature kNetworkServiceSandbox{"NetworkSer
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
