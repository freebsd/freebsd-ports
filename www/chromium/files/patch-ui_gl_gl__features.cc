--- ui/gl/gl_features.cc.orig	2020-11-16 15:04:56 UTC
+++ ui/gl/gl_features.cc
@@ -14,7 +14,7 @@ namespace features {
 const base::Feature kDefaultPassthroughCommandDecoder{
   "DefaultPassthroughCommandDecoder",
 #if defined(OS_WIN) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(CHROMECAST_BUILD))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(CHROMECAST_BUILD)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
