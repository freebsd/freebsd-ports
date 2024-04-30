--- src/3rdparty/chromium/gpu/config/gpu_finch_features.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/gpu/config/gpu_finch_features.cc
@@ -58,7 +58,7 @@ CONSTINIT const base::Feature kUseGles2ForOopR(
 CONSTINIT const base::Feature kUseGles2ForOopR(
              "UseGles2ForOopR",
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_DISABLED_BY_DEFAULT
 #else
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -142,7 +142,8 @@ CONSTINIT const base::Feature kDefaultEnableGpuRasteri
 CONSTINIT const base::Feature kDefaultEnableGpuRasterization(
              "DefaultEnableGpuRasterization",
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+    BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
