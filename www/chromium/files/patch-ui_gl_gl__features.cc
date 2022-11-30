--- ui/gl/gl_features.cc.orig	2022-11-30 08:12:58 UTC
+++ ui/gl/gl_features.cc
@@ -86,7 +86,7 @@ BASE_FEATURE(kDefaultPassthroughCommandDecoder,
              "DefaultPassthroughCommandDecoder",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) ||     \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
