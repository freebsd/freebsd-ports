--- chrome/browser/flag_descriptions.h.orig	2021-04-14 18:40:53 UTC
+++ chrome/browser/flag_descriptions.h
@@ -21,9 +21,9 @@
 #include "ppapi/buildflags/buildflags.h"
 #include "printing/buildflags/buildflags.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // This file declares strings used in chrome://flags. These messages are not
 // translated, because instead of end-users they target Chromium developers and
@@ -2900,7 +2900,7 @@ extern const char kEnableNewBadgeOnMenuItemsDescriptio
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 
 extern const char kEnableMediaFeedsName[];
@@ -2927,10 +2927,10 @@ extern const char kRemoteCopyProgressNotificationDescr
 extern const char kDirectManipulationStylusName[];
 extern const char kDirectManipulationStylusDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kCommanderName[];
 extern const char kCommanderDescription[];
@@ -2941,7 +2941,7 @@ extern const char kDesktopRestructuredLanguageSettings
 extern const char kDesktopDetailedLanguageSettingsName[];
 extern const char kDesktopDetailedLanguageSettingsDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS) || defined(OS_LINUX)
 #if BUILDFLAG(USE_TCMALLOC)
@@ -2962,11 +2962,11 @@ extern const char kWebShareDescription[];
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
 extern const char kEnableEphemeralGuestProfilesOnDesktopName[];
 extern const char kEnableEphemeralGuestProfilesOnDesktopDescription[];
-#endif  // defined(OS_WIN) || (defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || (defined(OS_LINUX) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_MAC)
 
 // Feature flags --------------------------------------------------------------
@@ -3023,12 +3023,12 @@ extern const char kAutofillCreditCardUploadDescription
 
 #endif  // defined(TOOLKIT_VIEWS) || defined(OS_ANDROID)
 
-#if !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 extern const char kSendWebUIJavaScriptErrorReportsName[];
 extern const char kSendWebUIJavaScriptErrorReportsDescription[];
 #endif
 
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
