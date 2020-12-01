--- chrome/browser/flag_descriptions.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -4549,15 +4549,15 @@ const char kEnableNewBadgeOnMenuItemsDescription[] =
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 const char kWebGL2ComputeContextName[] = "WebGL 2.0 Compute";
 const char kWebGL2ComputeContextDescription[] =
     "Enable the use of WebGL 2.0 Compute API.";
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 
 const char kEnableMediaFeedsName[] = "Enables Media Feeds";
@@ -4601,17 +4601,17 @@ const char kRemoteCopyProgressNotificationDescription[
     "Enables progress notifications to be shown for the remote copy feature "
     "when receiving a message.";
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 
 const char kDirectManipulationStylusName[] = "Direct Manipulation Stylus";
 const char kDirectManipulationStylusDescription[] =
     "If enabled, Chrome will scroll web pages on stylus drag.";
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_CHROMEOS)
@@ -4623,14 +4623,14 @@ const char kWebContentsOcclusionDescription[] =
 
 #endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_CHROMEOS)
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 #if BUILDFLAG(USE_TCMALLOC)
 const char kDynamicTcmallocName[] = "Dynamic Tcmalloc Tuning";
 const char kDynamicTcmallocDescription[] =
     "Allows tcmalloc to dynamically adjust tunables based on system resource "
     "utilization.";
 #endif  // BUILDFLAG(USE_TCMALLOC)
-#endif  // #if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#endif  // #if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 const char kUserDataSnapshotName[] = "Enable user data snapshots";
@@ -4646,12 +4646,12 @@ const char kWebShareDescription[] =
     "platforms.";
 #endif  // defined(OS_WIN) || defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
 const char kEnableEphemeralGuestProfilesOnDesktopName[] =
     "Enable ephemeral Guest profiles on Desktop";
 const char kEnableEphemeralGuestProfilesOnDesktopDescription[] =
     "Enables ephemeral Guest profiles on Windows, Linux, and Mac.";
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
 
 // Feature flags --------------------------------------------------------------
 
