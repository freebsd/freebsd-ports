--- content/public/common/content_switches.cc.orig	2026-07-01 06:24:19 UTC
+++ content/public/common/content_switches.cc
@@ -349,6 +349,8 @@ const char kEnableIsolatedWebAppsInRenderer[] =
 // builds.
 const char kEnableLogging[]                 = "enable-logging";
 
+const char kDisableUnveil[]                 = "disable-unveil";
+
 // Enables the type, downlinkMax attributes of the NetInfo API. Also, enables
 // triggering of change attribute of the NetInfo API when there is a change in
 // the connection type.
@@ -949,7 +951,7 @@ const char kPreventResizingContentsForTesting[] =
     "prevent-resizing-contents-for-testing";
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
