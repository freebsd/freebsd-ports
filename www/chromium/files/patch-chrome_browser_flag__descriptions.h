--- chrome/browser/flag_descriptions.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/flag_descriptions.h
@@ -22,7 +22,7 @@
 #include "printing/buildflags/buildflags.h"
 #include "third_party/blink/public/common/buildflags.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
@@ -3081,7 +3081,7 @@ extern const char kDownloadShelfWebUIDescription[];
 // Random platform combinations -----------------------------------------------
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 
 extern const char kWebUIBrandingUpdateName[];
 extern const char kWebUIBrandingUpdateDescription[];
@@ -3093,7 +3093,7 @@ extern const char kWebuiFeedbackDescription[];
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
 
 extern const char kCommanderName[];
 extern const char kCommanderDescription[];
@@ -3107,7 +3107,7 @@ extern const char kDesktopDetailedLanguageSettingsDesc
 #endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined
         // (OS_FUCHSIA)
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 #if BUILDFLAG(USE_TCMALLOC)
 extern const char kDynamicTcmallocName[];
 extern const char kDynamicTcmallocDescription[];
@@ -3119,7 +3119,7 @@ extern const char kWebShareName[];
 extern const char kWebShareDescription[];
 #endif  // defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_MAC)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kOzonePlatformHintChoiceDefault[];
 extern const char kOzonePlatformHintChoiceAuto[];
 extern const char kOzonePlatformHintChoiceX11[];
@@ -3201,7 +3201,7 @@ extern const char kElasticOverscrollDescription[];
 #endif  // defined(OS_WIN) || defined(OS_ANDROID)
 
 #if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    defined(OS_MAC) || defined(OS_FUCHSIA)
+    defined(OS_MAC) || defined(OS_FUCHSIA) || defined(OS_BSD)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
 #endif
