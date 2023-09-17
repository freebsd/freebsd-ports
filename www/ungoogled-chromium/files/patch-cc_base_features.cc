--- cc/base/features.cc.orig	2023-09-17 07:59:53 UTC
+++ cc/base/features.cc
@@ -71,7 +71,7 @@ BASE_FEATURE(kNormalPriorityImageDecoding,
 
 BASE_FEATURE(kUseDMSAAForTiles,
              "UseDMSAAForTiles",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
