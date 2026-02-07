--- src/3rdparty/chromium/content/public/common/content_features.cc.orig	2025-10-02 00:36:39 UTC
+++ src/3rdparty/chromium/content/public/common/content_features.cc
@@ -72,7 +72,7 @@ BASE_FEATURE(kAudioServiceLaunchOnStartup,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 // Runs the audio service in a separate process.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAudioServiceOutOfProcess,
              "AudioServiceOutOfProcess",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -1238,9 +1238,9 @@ BASE_FEATURE(kWebAssemblyTiering,
 
 // Enable WebAssembly trap handler.
 #if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) ||  \
-      BUILDFLAG(IS_MAC)) &&                                                  \
+      BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) &&                             \
      defined(ARCH_CPU_X86_64)) ||                                            \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)) && \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) && \
      defined(ARCH_CPU_ARM64))
 BASE_FEATURE(kWebAssemblyTrapHandler,
              "WebAssemblyTrapHandler",
@@ -1296,7 +1296,11 @@ BASE_FEATURE(kWebUIJSErrorReportingExtended,
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Controls whether the WebXR Device API is enabled.
 BASE_FEATURE(kWebXr, "WebXR", base::FEATURE_ENABLED_BY_DEFAULT);
