--- content/public/common/content_features.cc.orig	2023-11-22 14:00:11 UTC
+++ content/public/common/content_features.cc
@@ -40,7 +40,7 @@ BASE_FEATURE(kAudioServiceOutOfProcess,
              "AudioServiceOutOfProcess",
 // TODO(crbug.com/1052397): Remove !IS_CHROMEOS_LACROS once lacros starts being
 // built with OS_CHROMEOS instead of OS_LINUX.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -52,7 +52,7 @@ BASE_FEATURE(kAudioServiceOutOfProcess,
 // kAudioServiceOutOfProcess feature is enabled.
 BASE_FEATURE(kAudioServiceSandbox,
              "AudioServiceSandbox",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1131,7 +1131,7 @@ BASE_FEATURE(kWebAssemblyTiering,
 BASE_FEATURE(kWebAssemblyTrapHandler,
              "WebAssemblyTrapHandler",
 #if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-      BUILDFLAG(IS_MAC)) &&                                                 \
+      BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) &&                            \
      defined(ARCH_CPU_X86_64)) ||                                           \
     (BUILDFLAG(IS_MAC) && defined(ARCH_CPU_ARM64))
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -1172,7 +1172,11 @@ BASE_FEATURE(kWebUICodeCache,
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Controls whether the WebXR Device API is enabled.
 BASE_FEATURE(kWebXr, "WebXR", base::FEATURE_ENABLED_BY_DEFAULT);
