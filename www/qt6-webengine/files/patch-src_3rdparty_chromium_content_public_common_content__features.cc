--- src/3rdparty/chromium/content/public/common/content_features.cc.orig	2023-08-16 19:50:41 UTC
+++ src/3rdparty/chromium/content/public/common/content_features.cc
@@ -39,7 +39,7 @@ CONSTINIT const base::Feature kAudioServiceOutOfProces
              "AudioServiceOutOfProcess",
 // TODO(crbug.com/1052397): Remove !IS_CHROMEOS_LACROS once lacros starts being
 // built with OS_CHROMEOS instead of OS_LINUX.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -51,7 +51,7 @@ CONSTINIT const base::Feature kAudioServiceSandbox(
 // kAudioServiceOutOfProcess feature is enabled.
 CONSTINIT const base::Feature kAudioServiceSandbox(
              "AudioServiceSandbox",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -547,7 +547,7 @@ BASE_FEATURE(kGreaseUACH, "GreaseUACH", base::FEATURE_
 // (activated by kUserAgentClientHint)
 BASE_FEATURE(kGreaseUACH, "GreaseUACH", base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Supports proxying thread type changes of renderer processes to browser
 // process and having browser process handle adjusting thread properties (nice
 // value, c-group, latency sensitivity...) for renderers which have sandbox
@@ -1367,7 +1367,7 @@ CONSTINIT const base::Feature kWebAssemblyTrapHandler(
 CONSTINIT const base::Feature kWebAssemblyTrapHandler(
              "WebAssemblyTrapHandler",
 #if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-      BUILDFLAG(IS_MAC)) &&                                                 \
+      BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) &&                            \
      defined(ARCH_CPU_X86_64)) ||                                           \
     (BUILDFLAG(IS_MAC) && defined(ARCH_CPU_ARM64))
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -1425,7 +1425,11 @@ BASE_FEATURE(kWebUICodeCache,
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Controls whether the WebXR Device API is enabled.
 BASE_FEATURE(kWebXr, "WebXR", base::FEATURE_ENABLED_BY_DEFAULT);
