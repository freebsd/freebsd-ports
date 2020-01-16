--- chrome/browser/flag_descriptions.cc.orig	2019-12-16 21:51:23 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -3744,7 +3744,7 @@ const char kZeroStateFilesDescription[] =
 
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 const char kTerminalSystemAppName[] = "Terminal System App";
 const char kTerminalSystemAppDescription[] =
     "Enables the Terminal System App at chrome://terminal which is used for "
@@ -3757,7 +3757,7 @@ const char kDynamicTcmallocDescription[] =
     "utilization.";
 #endif  // BUILDFLAG(USE_TCMALLOC)
 
-#endif  // #if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#endif  // #if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 
 // All views-based platforms --------------------------------------------------
 
@@ -3782,13 +3782,13 @@ const char kReopenTabInProductHelpDescription[] =
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 const char kWebGL2ComputeContextName[] = "WebGL 2.0 Compute";
 const char kWebGL2ComputeContextDescription[] =
     "Enable the use of WebGL 2.0 Compute API.";
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_CLICK_TO_CALL)
 
@@ -3806,7 +3806,7 @@ const char kClickToCallUIDescription[] =
 
 #endif  // BUILDFLAG(ENABLE_CLICK_TO_CALL)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kDirectManipulationStylusName[] = "Direct Manipulation Stylus";
 const char kDirectManipulationStylusDescription[] =
@@ -3825,7 +3825,7 @@ const char kSyncClipboardServiceName[] = "Sync Clipboa
 const char kSyncClipboardServiceDescription[] =
     "Enables clipboard syncing via Chrome Sync.";
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
