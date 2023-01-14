--- src/3rdparty/chromium/ui/gl/gl_features.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/gl/gl_features.cc
@@ -83,7 +83,7 @@ const base::Feature kDefaultPassthroughCommandDecoder 
 const base::Feature kDefaultPassthroughCommandDecoder {
   "DefaultPassthroughCommandDecoder",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) ||              \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) && \
      !defined(CHROMECAST_BUILD)) ||                            \
     BUILDFLAG(IS_MAC)
       base::FEATURE_ENABLED_BY_DEFAULT
