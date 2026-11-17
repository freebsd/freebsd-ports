--- src/chrome/browser/chrome_content_browser_client_navigation_throttles.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/chrome_content_browser_client_navigation_throttles.cc
@@ -149,7 +149,7 @@
 #include "chrome/browser/captive_portal/captive_portal_service_factory.h"
 #endif  // BUILDFLAG(ENABLE_CAPTIVE_PORTAL_DETECTION)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_navigation_throttle.h"
 #include "chrome/browser/enterprise/profile_management/oidc_auth_response_capture_navigation_throttle.h"
 #include "chrome/browser/enterprise/profile_management/profile_management_navigation_throttle.h"
@@ -452,7 +452,7 @@ void CreateAndAddChromeThrottlesForNavig
     TypedNavigationUpgradeThrottle::MaybeCreateAndAdd(registry);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   WebAppSettingsNavigationThrottle::MaybeCreateAndAdd(registry);
   profile_management::ProfileManagementNavigationThrottle::MaybeCreateAndAdd(
       registry);
@@ -470,7 +470,7 @@ void CreateAndAddChromeThrottlesForNavig
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   enterprise_connectors::DeviceTrustNavigationThrottle::MaybeCreateAndAdd(
       registry);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) ||
@@ -525,7 +525,7 @@ void CreateAndAddChromeThrottlesForNavig
       registry, ui_manager);
 #endif  // BUILDFLAG(SAFE_BROWSING_AVAILABLE)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherNavigationThrottle::MaybeCreateAndAdd(
       registry);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
