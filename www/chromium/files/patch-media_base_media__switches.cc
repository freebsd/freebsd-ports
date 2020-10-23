--- media/base/media_switches.cc.orig	2020-09-08 19:14:07 UTC
+++ media/base/media_switches.cc
@@ -354,7 +354,7 @@ const base::Feature kGav1VideoDecoder{"Gav1VideoDecode
 const base::Feature kGlobalMediaControls {
   "GlobalMediaControls",
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -379,7 +379,7 @@ const base::Feature kGlobalMediaControlsOverlayControl
 const base::Feature kGlobalMediaControlsPictureInPicture {
   "GlobalMediaControlsPictureInPicture",
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
