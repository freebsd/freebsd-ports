--- content/public/common/content_switches.cc.orig	2014-10-10 09:15:31 UTC
+++ content/public/common/content_switches.cc
@@ -924,7 +924,7 @@
     "disable-vaapi-accelerated-video-encode";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
