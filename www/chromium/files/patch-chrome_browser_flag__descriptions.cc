--- chrome/browser/flag_descriptions.cc.orig	2020-09-08 19:14:00 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -4103,15 +4103,15 @@ const char kEnableNewBadgeOnMenuItemsDescription[] =
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 const char kWebGL2ComputeContextName[] = "WebGL 2.0 Compute";
 const char kWebGL2ComputeContextDescription[] =
     "Enable the use of WebGL 2.0 Compute API.";
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 
 const char kEnableMediaFeedsName[] = "Enables Media Feeds";
@@ -4143,16 +4143,16 @@ const char kRemoteCopyProgressNotificationDescription[
     "Enables progress notifications to be shown for the remote copy feature "
     "when receiving a message.";
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kDirectManipulationStylusName[] = "Direct Manipulation Stylus";
 const char kDirectManipulationStylusDescription[] =
     "If enabled, Chrome will scroll web pages on stylus drag.";
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
@@ -4163,14 +4163,14 @@ const char kWebContentsOcclusionDescription[] =
 
 #endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
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
