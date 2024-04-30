--- src/3rdparty/chromium/cc/base/features.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/cc/base/features.cc
@@ -85,7 +85,7 @@ CONSTINIT const base::Feature kUseDMSAAForTiles(
 // be using a separate flag to control the launch on GL.
 CONSTINIT const base::Feature kUseDMSAAForTiles(
              "UseDMSAAForTiles",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
