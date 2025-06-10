--- src/3rdparty/chromium/content/public/common/content_features.cc.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/chromium/content/public/common/content_features.cc
@@ -61,7 +61,7 @@ BASE_FEATURE(kAudioServiceLaunchOnStartup,
 
 // Runs the audio service in a separate process.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 BASE_FEATURE(kAudioServiceOutOfProcess,
              "AudioServiceOutOfProcess",
              // TODO(crbug.com/1052397): Remove !IS_CHROMEOS_LACROS once lacros
@@ -1226,9 +1226,9 @@ BASE_FEATURE(kWebAssemblyTiering,
 
 // Enable WebAssembly trap handler.
 #if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) ||  \
-      BUILDFLAG(IS_MAC)) &&                                                  \
+      BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) &&                                                  \
      defined(ARCH_CPU_X86_64)) ||                                            \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)) && \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) && \
      defined(ARCH_CPU_ARM64))
 BASE_FEATURE(kWebAssemblyTrapHandler,
              "WebAssemblyTrapHandler",
@@ -1268,7 +1268,11 @@ BASE_FEATURE(kWebUICodeCache,
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Controls whether the WebXR Device API is enabled.
 BASE_FEATURE(kWebXr, "WebXR", base::FEATURE_ENABLED_BY_DEFAULT);
