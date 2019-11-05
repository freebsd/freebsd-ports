--- content/public/common/content_switches.cc.orig	2019-10-21 19:06:32 UTC
+++ content/public/common/content_switches.cc
@@ -980,7 +980,7 @@ const char kEnableAggressiveDOMStorageFlushing[] =
 // Enable indication that browser is controlled by automation.
 const char kEnableAutomation[] = "enable-automation";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
