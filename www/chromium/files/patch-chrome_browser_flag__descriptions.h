--- chrome/browser/flag_descriptions.h.orig	2019-12-16 21:51:23 UTC
+++ chrome/browser/flag_descriptions.h
@@ -20,9 +20,9 @@
 #include "ui/android/buildflags.h"
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 // This file declares strings used in chrome://flags. These messages are not
 // translated, because instead of end-users they target Chromium developers and
@@ -2233,7 +2233,7 @@ extern const char kZeroStateFilesDescription[];
 
 #endif  // #if defined(OS_CHROMEOS)
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kTerminalSystemAppName[];
 extern const char kTerminalSystemAppDescription[];
 
@@ -2242,7 +2242,7 @@ extern const char kDynamicTcmallocName[];
 extern const char kDynamicTcmallocDescription[];
 #endif  // BUILDFLAG(USE_TCMALLOC)
 
-#endif  // #if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#endif  // #if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 
 // All views-based platforms --------------------------------------------------
 
@@ -2261,12 +2261,12 @@ extern const char kReopenTabInProductHelpDescription[]
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 extern const char kWebGL2ComputeContextName[];
 extern const char kWebGL2ComputeContextDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_CLICK_TO_CALL)
 
@@ -2278,7 +2278,7 @@ extern const char kClickToCallUIDescription[];
 
 #endif  // BUILDFLAG(ENABLE_CLICK_TO_CALL)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kDirectManipulationStylusName[];
 extern const char kDirectManipulationStylusDescription[];
@@ -2292,7 +2292,7 @@ extern const char kProfileMenuRevampDescription[];
 extern const char kSyncClipboardServiceName[];
 extern const char kSyncClipboardServiceDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
