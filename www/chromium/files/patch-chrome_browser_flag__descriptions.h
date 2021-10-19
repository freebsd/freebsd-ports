--- chrome/browser/flag_descriptions.h.orig	2021-09-24 04:25:58 UTC
+++ chrome/browser/flag_descriptions.h
@@ -22,9 +22,9 @@
 #include "printing/buildflags/buildflags.h"
 #include "third_party/blink/public/common/buildflags.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // This file declares strings used in chrome://flags. These messages are not
 // translated, because instead of end-users they target Chromium developers and
@@ -2954,7 +2954,7 @@ extern const char kDownloadShelfWebUIDescription[];
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 extern const char kEnableOopPrintDriversName[];
@@ -2969,10 +2969,10 @@ extern const char kWebuiFeedbackDescription[];
 extern const char kSettingsLandingPageRedesignName[];
 extern const char kSettingsLandingPageRedesignDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kCommanderName[];
 extern const char kCommanderDescription[];
@@ -2983,7 +2983,7 @@ extern const char kDesktopRestructuredLanguageSettings
 extern const char kDesktopDetailedLanguageSettingsName[];
 extern const char kDesktopDetailedLanguageSettingsDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS) || defined(OS_LINUX)
 #if BUILDFLAG(USE_TCMALLOC)
@@ -3002,10 +3002,10 @@ extern const char kWebShareName[];
 extern const char kWebShareDescription[];
 #endif  // defined(OS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_MAC)
 
-#if defined(OS_LINUX) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
 extern const char kUseOzonePlatformName[];
 extern const char kUseOzonePlatformDescription[];
-#endif  // defined(OS_LINUX) && defined(USE_OZONE)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
 
 // Feature flags --------------------------------------------------------------
 
@@ -3061,7 +3061,7 @@ extern const char kElasticOverscrollName[];
 extern const char kElasticOverscrollDescription[];
 #endif  // defined(OS_WIN) || defined(OS_ANDROID)
 
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
