--- content/public/common/content_features.cc.orig	2025-10-28 14:29:43 UTC
+++ content/public/common/content_features.cc
@@ -102,7 +102,7 @@ BASE_FEATURE(AudioServiceLaunchOnStartup, base::FEATUR
 
 // Runs the audio service in a separate process.
 BASE_FEATURE(AudioServiceOutOfProcess,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1164,9 +1164,10 @@ BASE_FEATURE(WebAssemblyTiering, base::FEATURE_ENABLED
 // Enable WebAssembly trap handler.
 BASE_FEATURE(WebAssemblyTrapHandler,
 #if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) ||  \
-      BUILDFLAG(IS_MAC)) &&                                                  \
+      BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) &&                             \
      defined(ARCH_CPU_X86_64)) ||                                            \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)) && \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) ||  \
+      BUILDFLAG(IS_BSD)) &&                                                  \
      defined(ARCH_CPU_ARM64))
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -1214,7 +1215,11 @@ BASE_FEATURE(WebUIJSErrorReportingExtended, base::FEAT
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Apply `PrefetchPriority::kHighest` for Webview Prefetch API.
 BASE_FEATURE(WebViewPrefetchHighestPrefetchPriority,
