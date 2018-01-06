--- src/3rdparty/chromium/content/public/common/content_switches.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/public/common/content_switches.cc
@@ -992,7 +992,7 @@ const char kDisableVaapiAcceleratedVideo
     "disable-vaapi-accelerated-video-encode";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
