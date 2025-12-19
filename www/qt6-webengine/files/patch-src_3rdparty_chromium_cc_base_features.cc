--- src/3rdparty/chromium/cc/base/features.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/cc/base/features.cc
@@ -52,7 +52,7 @@ const base::FeatureParam<int> kDeferImplInvalidationFr
 // Note that kUseDMSAAForTiles only controls vulkan launch on android. We will
 // be using a separate flag to control the launch on GL.
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUseDMSAAForTiles,
              "UseDMSAAForTiles",
              base::FEATURE_ENABLED_BY_DEFAULT);
