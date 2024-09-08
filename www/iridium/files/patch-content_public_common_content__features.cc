--- content/public/common/content_features.cc.orig	2024-08-27 06:28:16 UTC
+++ content/public/common/content_features.cc
@@ -36,7 +36,7 @@ BASE_FEATURE(kAudioServiceOutOfProcess,
 // TODO(crbug.com/40118868): Remove !IS_CHROMEOS_LACROS once lacros starts being
 // built with OS_CHROMEOS instead of OS_LINUX.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1128,9 +1128,9 @@ BASE_FEATURE(kWebAssemblyTiering,
 BASE_FEATURE(kWebAssemblyTrapHandler,
              "WebAssemblyTrapHandler",
 #if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) ||  \
-      BUILDFLAG(IS_MAC)) &&                                                  \
+      BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) &&                                                  \
      defined(ARCH_CPU_X86_64)) ||                                            \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)) && \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) && \
      defined(ARCH_CPU_ARM64))
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -1167,7 +1167,11 @@ BASE_FEATURE(kWebUICodeCache,
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Controls whether the WebXR Device API is enabled.
 BASE_FEATURE(kWebXr, "WebXR", base::FEATURE_ENABLED_BY_DEFAULT);
