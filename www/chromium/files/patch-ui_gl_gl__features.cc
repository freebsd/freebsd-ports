--- ui/gl/gl_features.cc.orig	2022-05-19 14:06:27 UTC
+++ ui/gl/gl_features.cc
@@ -83,7 +83,7 @@ const base::Feature kAndroidFrameDeadline{"AndroidFram
 const base::Feature kDefaultPassthroughCommandDecoder {
   "DefaultPassthroughCommandDecoder",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) ||              \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) && \
      !defined(CHROMECAST_BUILD)) ||                            \
     BUILDFLAG(IS_MAC)
       base::FEATURE_ENABLED_BY_DEFAULT
