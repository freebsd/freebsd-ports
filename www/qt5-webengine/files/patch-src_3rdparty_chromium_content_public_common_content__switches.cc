--- src/3rdparty/chromium/content/public/common/content_switches.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/public/common/content_switches.cc
@@ -907,7 +907,7 @@ const char kDisableAcceleratedVideoDecode[] =
 const char kDisableAcceleratedVideoDecode[] =
     "disable-accelerated-video-decode";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)) || defined(OS_BSD)
 // Enables hardware acceleration of video decoding on linux. (defaults to off)
 const char kEnableAcceleratedVideoDecode[] = "enable-accelerated-video-decode";
 #endif
@@ -971,7 +971,7 @@ const char kEnableAutomation[] = "enable-automation";
 // Enable indication that browser is controlled by automation.
 const char kEnableAutomation[] = "enable-automation";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
