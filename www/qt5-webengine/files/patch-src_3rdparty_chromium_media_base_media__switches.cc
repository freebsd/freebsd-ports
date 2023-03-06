--- src/3rdparty/chromium/media/base/media_switches.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/media/base/media_switches.cc
@@ -361,7 +361,7 @@ const base::Feature kGlobalMediaControls {
 const base::Feature kGlobalMediaControls {
   "GlobalMediaControls",
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -390,7 +390,7 @@ const base::Feature kGlobalMediaControlsPictureInPictu
 const base::Feature kGlobalMediaControlsPictureInPicture {
   "GlobalMediaControlsPictureInPicture",
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
