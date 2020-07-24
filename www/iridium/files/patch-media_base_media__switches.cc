--- media/base/media_switches.cc.orig	2020-03-17 10:01:08 UTC
+++ media/base/media_switches.cc
@@ -331,7 +331,7 @@ const base::Feature kFallbackAfterDecodeError{"Fallbac
 const base::Feature kGlobalMediaControls {
   "GlobalMediaControls",
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
