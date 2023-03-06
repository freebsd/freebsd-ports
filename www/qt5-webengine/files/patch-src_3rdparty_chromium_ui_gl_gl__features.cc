--- src/3rdparty/chromium/ui/gl/gl_features.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/gl/gl_features.cc
@@ -14,7 +14,7 @@ const base::Feature kDefaultPassthroughCommandDecoder{
 const base::Feature kDefaultPassthroughCommandDecoder{
   "DefaultPassthroughCommandDecoder",
 #if defined(OS_WIN) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(CHROMECAST_BUILD))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(CHROMECAST_BUILD)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
