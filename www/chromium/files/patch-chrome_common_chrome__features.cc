--- chrome/common/chrome_features.cc.orig	2023-07-16 15:47:57 UTC
+++ chrome/common/chrome_features.cc
@@ -82,7 +82,7 @@ BASE_FEATURE(kAsyncDns,
 );
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Enables or disables the Autofill survey triggered by opening a prompt to
 // save address info.
 BASE_FEATURE(kAutofillAddressSurvey,
@@ -100,7 +100,7 @@ BASE_FEATURE(kAutofillPasswordSurvey,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
@@ -291,7 +291,7 @@ BASE_FEATURE(kDesktopPWAsEnforceWebAppSettingsPolicy,
 // Enables or disables Desktop PWAs to be auto-started on OS login.
 BASE_FEATURE(kDesktopPWAsRunOnOsLogin,
              "DesktopPWAsRunOnOsLogin",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -326,7 +326,7 @@ BASE_FEATURE(kDesktopPWAsWebBundles,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Controls whether Chrome Apps are supported. See https://crbug.com/1221251.
 // If the feature is disabled, Chrome Apps continue to work. If enabled, Chrome
 // Apps will not launch and will be marked in the UI as deprecated.
@@ -353,7 +353,7 @@ BASE_FEATURE(kDisruptiveNotificationPermissionRevocati
 BASE_FEATURE(kDnsOverHttps,
              "DnsOverHttps",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -369,7 +369,7 @@ const base::FeatureParam<bool> kDnsOverHttpsFallbackPa
 const base::FeatureParam<bool> kDnsOverHttpsShowUiParam {
   &kDnsOverHttps, "ShowUi",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       true
 #else
       false
@@ -793,7 +793,7 @@ BASE_FEATURE(kKAnonymityServiceStorage,
              "KAnonymityServiceStorage",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kLinuxLowMemoryMonitor,
              "LinuxLowMemoryMonitor",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -806,7 +806,7 @@ constexpr base::FeatureParam<int> kLinuxLowMemoryMonit
     &kLinuxLowMemoryMonitor, "critical_level", 255};
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kListWebAppsSwitch,
              "ListWebAppsSwitch",
              base::FEATURE_DISABLED_BY_DEFAULT);
