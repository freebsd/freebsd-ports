--- cc/base/features.cc.orig	2025-01-25 09:34:31 UTC
+++ cc/base/features.cc
@@ -65,7 +65,7 @@ const base::FeatureParam<int> kDeferImplInvalidationFr
 // be using a separate flag to control the launch on GL.
 BASE_FEATURE(kUseDMSAAForTiles,
              "UseDMSAAForTiles",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
