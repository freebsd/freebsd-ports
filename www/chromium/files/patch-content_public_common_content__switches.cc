--- content/public/common/content_switches.cc.orig	2019-07-24 18:58:24 UTC
+++ content/public/common/content_switches.cc
@@ -949,7 +949,7 @@ const char kEnableAutomation[] = "enable-automation";
 const char kDisablePanelFitting[]           = "disable-panel-fitting";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
