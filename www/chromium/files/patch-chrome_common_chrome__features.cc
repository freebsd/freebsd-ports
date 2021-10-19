--- chrome/common/chrome_features.cc.orig	2021-09-24 04:26:00 UTC
+++ chrome/common/chrome_features.cc
@@ -82,13 +82,13 @@ const base::Feature kAsyncDns {
 #endif
 };
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
 const base::Feature kBackgroundModeAllowRestart{
     "BackgroundModeAllowRestart", base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 // Enable Borealis on Chrome OS.
@@ -99,13 +99,13 @@ const base::Feature kBorealis{"Borealis", base::FEATUR
 const base::Feature kChangePictureVideoMode{"ChangePictureVideoMode",
                                             base::FEATURE_ENABLED_BY_DEFAULT};
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 // Controls whether Chrome Apps are supported. See https://crbug.com/1221251.
 // If the feature is disabled, Chrome Apps continue to work. If enabled, Chrome
 // Apps will not launch and will be marked in the UI as deprecated.
 const base::Feature kChromeAppsDeprecation{"ChromeAppsDeprecation",
                                            base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 const base::Feature kChromeCleanupScanCompletedNotification{
@@ -216,12 +216,12 @@ const base::Feature kDefaultPinnedAppsUpdate2021Q2{
     "DefaultPinnedAppsUpdate2021Q2", base::FEATURE_ENABLED_BY_DEFAULT};
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_MAC) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 // Enables Desktop PWAs shortcuts menu to be visible and executable in ChromeOS,
 // MacOS and Linux.
 const base::Feature kDesktopPWAsAppIconShortcutsMenuUI{
   "DesktopPWAsAppIconShortcutsMenuUI",
-#if defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
@@ -273,7 +273,7 @@ const base::Feature kDesktopPWAsNotificationIconAndTit
 // Enables or disables Desktop PWAs to be auto-started on OS login.
 const base::Feature kDesktopPWAsRunOnOsLogin {
   "DesktopPWAsRunOnOsLogin",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -558,7 +558,7 @@ const base::Feature kIncognitoReauthenticationForAndro
 const base::Feature kIncognitoNtpRevamp{"IncognitoNtpRevamp",
                                         base::FEATURE_DISABLED_BY_DEFAULT};
 
-#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 // When enabled, removes any theme or background customization done by the user
 // on the Incognito UI.
