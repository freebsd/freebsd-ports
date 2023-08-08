--- src/3rdparty/chromium/sandbox/policy/features.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/sandbox/policy/features.cc
@@ -15,7 +15,11 @@ BASE_FEATURE(kNetworkServiceSandbox,
 // (Only causes an effect when feature kNetworkService is enabled.)
 BASE_FEATURE(kNetworkServiceSandbox,
              "NetworkServiceSandbox",
+#if BUILDFLAG(IS_BSD)
+             base::FEATURE_ENABLED_BY_DEFAULT);
+#else
              base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 #endif  // !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN)
