--- chrome/common/chrome_features.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/common/chrome_features.cc
@@ -113,7 +113,7 @@ const base::Feature kAsyncDns {
 };
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Enables or disables the Autofill survey triggered by opening a prompt to
 // save address info.
 const base::Feature kAutofillAddressSurvey{"AutofillAddressSurvey",
@@ -128,7 +128,7 @@ const base::Feature kAutofillPasswordSurvey{"AutofillP
                                             base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
@@ -145,7 +145,7 @@ const base::Feature kBorealis{"Borealis", base::FEATUR
 const base::Feature kChangePictureVideoMode{"ChangePictureVideoMode",
                                             base::FEATURE_ENABLED_BY_DEFAULT};
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Controls whether Chrome Apps are supported. See https://crbug.com/1221251.
 // If the feature is disabled, Chrome Apps continue to work. If enabled, Chrome
 // Apps will not launch and will be marked in the UI as deprecated.
@@ -258,7 +258,7 @@ const base::Feature kPreinstalledWebAppInstallation{
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Enables Desktop PWAs shortcuts menu to be visible and executable in ChromeOS,
 // MacOS and Linux.
 const base::Feature kDesktopPWAsAppIconShortcutsMenuUI{
@@ -305,7 +305,7 @@ const base::Feature kDesktopPWAsNotificationIconAndTit
 // Enables or disables Desktop PWAs to be auto-started on OS login.
 const base::Feature kDesktopPWAsRunOnOsLogin {
   "DesktopPWAsRunOnOsLogin",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -339,7 +339,7 @@ const base::FeatureParam<int> kDisableHttpDiskCacheMem
 const base::Feature kDnsOverHttps {
   "DnsOverHttps",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -361,7 +361,7 @@ const base::FeatureParam<bool> kDnsOverHttpsFallbackPa
 const base::FeatureParam<bool> kDnsOverHttpsShowUiParam {
   &kDnsOverHttps, "ShowUi",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       true
 #else
       false
@@ -608,7 +608,7 @@ const base::Feature kImmersiveFullscreen{"ImmersiveFul
                                          base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const base::Feature kImproveAccessibilityTreeUsingLocalML{
     "ImproveAccessibilityTreeUsingLocalML", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
@@ -645,7 +645,7 @@ const base::Feature kIncognitoNtpRevamp{"IncognitoNtpR
                                         base::FEATURE_DISABLED_BY_DEFAULT};
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // When enabled, removes any theme or background customization done by the user
 // on the Incognito UI.
 const base::Feature kIncognitoBrandConsistencyForDesktop{
@@ -681,7 +681,7 @@ const base::Feature kLinkCapturingUiUpdate{"LinkCaptur
                                            base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 const base::Feature kLinuxLowMemoryMonitor{"LinuxLowMemoryMonitor",
                                            base::FEATURE_DISABLED_BY_DEFAULT};
@@ -694,7 +694,7 @@ constexpr base::FeatureParam<int> kLinuxLowMemoryMonit
     &kLinuxLowMemoryMonitor, "critical_level", 255};
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const base::Feature kListWebAppsSwitch{"ListWebAppsSwitch",
                                        base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
