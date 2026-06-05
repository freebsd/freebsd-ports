--- chrome/browser/chrome_content_browser_client_navigation_throttles.cc.orig	2026-06-04 10:12:25 UTC
+++ chrome/browser/chrome_content_browser_client_navigation_throttles.cc
@@ -145,7 +145,7 @@
 #include "chrome/browser/captive_portal/captive_portal_service_factory.h"
 #endif  // BUILDFLAG(ENABLE_CAPTIVE_PORTAL_DETECTION)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_navigation_throttle.h"
 #include "chrome/browser/enterprise/profile_management/oidc_auth_response_capture_navigation_throttle.h"
 #include "chrome/browser/enterprise/profile_management/profile_management_navigation_throttle.h"
@@ -449,7 +449,7 @@ void CreateAndAddChromeThrottlesForNavigation(
     TypedNavigationUpgradeThrottle::MaybeCreateAndAdd(registry);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   WebAppSettingsNavigationThrottle::MaybeCreateAndAdd(registry);
   profile_management::ProfileManagementNavigationThrottle::MaybeCreateAndAdd(
       registry);
@@ -467,7 +467,7 @@ void CreateAndAddChromeThrottlesForNavigation(
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   enterprise_connectors::DeviceTrustNavigationThrottle::MaybeCreateAndAdd(
       registry);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) ||
@@ -521,7 +521,7 @@ void CreateAndAddChromeThrottlesForNavigation(
       registry, ui_manager);
 #endif  // BUILDFLAG(SAFE_BROWSING_AVAILABLE)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherNavigationThrottle::MaybeCreateAndAdd(
       registry);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
