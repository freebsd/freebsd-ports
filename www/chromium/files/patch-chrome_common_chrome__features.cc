--- chrome/common/chrome_features.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/common/chrome_features.cc
@@ -104,7 +104,7 @@ const base::Feature kAsyncDns {
 };
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Enables or disables the Autofill survey triggered by opening a prompt to
 // save address info.
 const base::Feature kAutofillAddressSurvey{"AutofillAddressSurvey",
@@ -119,7 +119,7 @@ const base::Feature kAutofillPasswordSurvey{"AutofillP
                                             base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
@@ -287,7 +287,7 @@ const base::Feature kDesktopPWAsEnforceWebAppSettingsP
 // Enables or disables Desktop PWAs to be auto-started on OS login.
 const base::Feature kDesktopPWAsRunOnOsLogin {
   "DesktopPWAsRunOnOsLogin",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -303,7 +303,7 @@ const base::Feature kDesktopPWAsWebBundles{"DesktopPWA
                                            base::FEATURE_DISABLED_BY_DEFAULT};
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Serves web app settings at chrome://app-settings/<app-id>.
 const base::Feature kDesktopPWAsWebAppSettingsPage{
     "DesktopPWAsWebAppSettingsPage", base::FEATURE_ENABLED_BY_DEFAULT};
@@ -327,7 +327,7 @@ const base::Feature kDmTokenDeletion{"DmTokenDeletion"
 const base::Feature kDnsOverHttps {
   "DnsOverHttps",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -343,7 +343,7 @@ const base::FeatureParam<bool> kDnsOverHttpsFallbackPa
 const base::FeatureParam<bool> kDnsOverHttpsShowUiParam {
   &kDnsOverHttps, "ShowUi",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       true
 #else
       false
@@ -639,7 +639,7 @@ const base::Feature kIncognitoParamFilterEnabled{
 const base::Feature kIPHInWebUIDemo{"IPHInWebUIDemo",
                                     base::FEATURE_DISABLED_BY_DEFAULT};
 
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
