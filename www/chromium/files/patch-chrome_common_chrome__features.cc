--- chrome/common/chrome_features.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/common/chrome_features.cc
@@ -110,7 +110,7 @@ const base::Feature kAsyncDns {
 };
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Enables or disables the Autofill survey triggered by opening a prompt to
 // save address info.
 const base::Feature kAutofillAddressSurvey{"AutofillAddressSurvey",
@@ -125,7 +125,7 @@ const base::Feature kAutofillPasswordSurvey{"AutofillP
                                             base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
@@ -295,7 +295,7 @@ const base::Feature kDesktopPWAsNotificationIconAndTit
 // Enables or disables Desktop PWAs to be auto-started on OS login.
 const base::Feature kDesktopPWAsRunOnOsLogin {
   "DesktopPWAsRunOnOsLogin",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -317,7 +317,7 @@ const base::Feature kDesktopPWAsWebBundles{"DesktopPWA
                                            base::FEATURE_DISABLED_BY_DEFAULT};
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Serves web app settings at chrome://app-settings/<app-id>.
 const base::Feature kDesktopPWAsWebAppSettingsPage{
     "DesktopPWAsWebAppSettingsPage", base::FEATURE_ENABLED_BY_DEFAULT};
@@ -332,7 +332,7 @@ const base::Feature kChromeAppsDeprecation{"ChromeApps
 const base::Feature kDnsOverHttps {
   "DnsOverHttps",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -348,7 +348,7 @@ const base::FeatureParam<bool> kDnsOverHttpsFallbackPa
 const base::FeatureParam<bool> kDnsOverHttpsShowUiParam {
   &kDnsOverHttps, "ShowUi",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       true
 #else
       false
@@ -639,7 +639,7 @@ const base::Feature kKernelnextVMs{"KernelnextVMs",
                                    base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 const base::Feature kLinuxLowMemoryMonitor{"LinuxLowMemoryMonitor",
                                            base::FEATURE_DISABLED_BY_DEFAULT};
@@ -652,7 +652,7 @@ constexpr base::FeatureParam<int> kLinuxLowMemoryMonit
     &kLinuxLowMemoryMonitor, "critical_level", 255};
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const base::Feature kListWebAppsSwitch{"ListWebAppsSwitch",
                                        base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
