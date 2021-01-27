--- content/public/common/content_switches.cc.orig	2021-01-18 21:28:57 UTC
+++ content/public/common/content_switches.cc
@@ -895,7 +895,7 @@ const char kWebXrRuntimeWMR[] = "windows-mixed-reality
 const char kDisableAcceleratedVideoDecode[] =
     "disable-accelerated-video-decode";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)) || defined(OS_BSD)
 // Enables hardware acceleration of video decoding on linux. (defaults to off)
 const char kEnableAcceleratedVideoDecode[] = "enable-accelerated-video-decode";
 #endif
@@ -959,7 +959,7 @@ const char kEnableAggressiveDOMStorageFlushing[] =
 // Enable indication that browser is controlled by automation.
 const char kEnableAutomation[] = "enable-automation";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
