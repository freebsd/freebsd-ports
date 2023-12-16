--- src/3rdparty/chromium/gpu/config/gpu_finch_features.cc.orig	2023-08-16 19:50:41 UTC
+++ src/3rdparty/chromium/gpu/config/gpu_finch_features.cc
@@ -57,7 +57,7 @@ CONSTINIT const base::Feature kUseGles2ForOopR(
 CONSTINIT const base::Feature kUseGles2ForOopR(
              "UseGles2ForOopR",
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_DISABLED_BY_DEFAULT
 #else
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -135,7 +135,8 @@ CONSTINIT const base::Feature kDefaultEnableGpuRasteri
 CONSTINIT const base::Feature kDefaultEnableGpuRasterization(
              "DefaultEnableGpuRasterization",
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+    BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
