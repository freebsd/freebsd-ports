--- chrome/common/chrome_features.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/common/chrome_features.cc
@@ -110,7 +110,7 @@ const base::Feature kAsyncDns {
 };
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Enables or disables the Autofill survey triggered by opening a prompt to
 // save address info.
 const base::Feature kAutofillAddressSurvey{"AutofillAddressSurvey",
@@ -125,7 +125,7 @@ const base::Feature kAutofillPasswordSurvey{"AutofillP
                                             base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
@@ -142,7 +142,7 @@ const base::Feature kBorealis{"Borealis", base::FEATUR
 const base::Feature kChangePictureVideoMode{"ChangePictureVideoMode",
                                             base::FEATURE_ENABLED_BY_DEFAULT};
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 // Controls whether Chrome Apps are supported. See https://crbug.com/1221251.
 // If the feature is disabled, Chrome Apps continue to work. If enabled, Chrome
 // Apps will not launch and will be marked in the UI as deprecated.
@@ -255,7 +255,7 @@ const base::Feature kPreinstalledWebAppInstallation{
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
 // Enables Desktop PWAs shortcuts menu to be visible and executable in ChromeOS,
 // MacOS and Linux.
 const base::Feature kDesktopPWAsAppIconShortcutsMenuUI{
@@ -303,7 +303,7 @@ const base::Feature kDesktopPWAsNotificationIconAndTit
 // Enables or disables Desktop PWAs to be auto-started on OS login.
 const base::Feature kDesktopPWAsRunOnOsLogin {
   "DesktopPWAsRunOnOsLogin",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -337,7 +337,7 @@ const base::FeatureParam<int> kDisableHttpDiskCacheMem
 const base::Feature kDnsOverHttps {
   "DnsOverHttps",
 #if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_ANDROID) || defined(OS_LINUX)
+    defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -359,7 +359,7 @@ const base::FeatureParam<bool> kDnsOverHttpsFallbackPa
 const base::FeatureParam<bool> kDnsOverHttpsShowUiParam {
   &kDnsOverHttps, "ShowUi",
 #if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_ANDROID) || defined(OS_LINUX)
+    defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
       true
 #else
       false
@@ -633,7 +633,7 @@ const base::Feature kIncognitoNtpRevamp{"IncognitoNtpR
                                         base::FEATURE_DISABLED_BY_DEFAULT};
 
 #if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // When enabled, removes any theme or background customization done by the user
 // on the Incognito UI.
 const base::Feature kIncognitoBrandConsistencyForDesktop{
@@ -675,7 +675,7 @@ const base::Feature kKernelnextVMs{"KernelnextVMs",
                                    base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 const base::Feature kLinuxLowMemoryMonitor{"LinuxLowMemoryMonitor",
                                            base::FEATURE_DISABLED_BY_DEFAULT};
