--- cc/base/features.cc.orig	2025-12-10 15:04:57 UTC
+++ cc/base/features.cc
@@ -42,7 +42,7 @@ const base::FeatureParam<int> kDeferImplInvalidationFr
 // Note that kUseDMSAAForTiles only controls vulkan launch on android. We will
 // be using a separate flag to control the launch on GL.
 BASE_FEATURE(kUseDMSAAForTiles,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
