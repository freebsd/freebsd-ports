--- src/3rdparty/chromium/cc/base/features.cc.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/chromium/cc/base/features.cc
@@ -83,7 +83,7 @@ const base::FeatureParam<int> kDeferImplInvalidationFr
 // Note that kUseDMSAAForTiles only controls vulkan launch on android. We will
 // be using a separate flag to control the launch on GL.
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUseDMSAAForTiles,
              "UseDMSAAForTiles",
              base::FEATURE_ENABLED_BY_DEFAULT);
