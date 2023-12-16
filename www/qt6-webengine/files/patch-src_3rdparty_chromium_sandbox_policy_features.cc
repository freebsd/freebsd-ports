--- src/3rdparty/chromium/sandbox/policy/features.cc.orig	2022-11-30 08:12:58 UTC
+++ src/3rdparty/chromium/sandbox/policy/features.cc
@@ -15,7 +15,11 @@ namespace sandbox::policy::features {
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
