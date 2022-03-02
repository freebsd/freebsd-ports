--- ui/gl/gl_features.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/gl/gl_features.cc
@@ -72,7 +72,7 @@ bool IsDeviceBlocked(const char* field, const std::str
 const base::Feature kDefaultPassthroughCommandDecoder {
   "DefaultPassthroughCommandDecoder",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) ||              \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) && \
      !defined(CHROMECAST_BUILD))
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
