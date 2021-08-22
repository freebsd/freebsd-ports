--- ui/gl/gl_features.cc.orig	2021-07-19 18:45:44 UTC
+++ ui/gl/gl_features.cc
@@ -71,8 +71,8 @@ bool IsDeviceBlocked(const char* field, const std::str
 // Launched on Windows, still experimental on other platforms.
 const base::Feature kDefaultPassthroughCommandDecoder{
   "DefaultPassthroughCommandDecoder",
-#if defined(OS_WIN) ||                                       \
-    ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+#if defined(OS_WIN) ||                                                          \
+    ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) && \
      !defined(CHROMECAST_BUILD))
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
