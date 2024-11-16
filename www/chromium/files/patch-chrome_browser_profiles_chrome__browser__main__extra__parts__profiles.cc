--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2024-11-14 07:57:23 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -349,7 +349,7 @@
 #include "chrome/browser/profiles/gaia_info_update_service_factory.h"
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/policy/messaging_layer/util/manual_test_heartbeat_event_factory.h"
 #endif
 
@@ -429,18 +429,18 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.h"
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.h"
 #include "chrome/browser/enterprise/signals/user_permission_service_factory.h"
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/idle/idle_service_factory.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_service_factory.h"
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "chrome/browser/enterprise/client_certificates/certificate_store_factory.h"
@@ -700,7 +700,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   DiceBoundSessionCookieServiceFactory::GetInstance();
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 #endif  // BUILDFLAG(ENABLE_BOUND_SESSION_CREDENTIALS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherServiceFactory::GetInstance();
 #endif
   browser_sync::UserEventServiceFactory::GetInstance();
@@ -809,7 +809,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   enterprise_connectors::ConnectorsServiceFactory::GetInstance();
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   enterprise_connectors::DeviceTrustConnectorServiceFactory::GetInstance();
   enterprise_connectors::DeviceTrustServiceFactory::GetInstance();
 #endif
@@ -817,25 +817,25 @@ void ChromeBrowserMainExtraPartsProfiles::
   enterprise_connectors::ExtensionInstallEventRouterFactory::GetInstance();
   enterprise_connectors::ExtensionTelemetryEventRouterFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   enterprise_connectors::LocalBinaryUploadServiceFactory::GetInstance();
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   enterprise_idle::IdleServiceFactory::GetInstance();
 #endif
 #if !BUILDFLAG(IS_CHROMEOS)
   enterprise_reporting::CloudProfileReportingServiceFactory::GetInstance();
 #endif
   enterprise_reporting::LegacyTechServiceFactory::GetInstance();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   enterprise_signals::SignalsAggregatorFactory::GetInstance();
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   enterprise_signals::UserPermissionServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   enterprise_signin::EnterpriseSigninServiceFactory::GetInstance();
 #endif
 #if BUILDFLAG(ENABLE_SESSION_SERVICE)
@@ -958,7 +958,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_ANDROID)
   MerchantViewerDataManagerFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
   NavigationPredictorKeyedServiceFactory::GetInstance();
@@ -1060,7 +1060,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_CHROMEOS)
   policy::PolicyCertServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   policy::ProfileTokenPolicyWebSigninServiceFactory::GetInstance();
   policy::UserPolicyOidcSigninServiceFactory::GetInstance();
 #endif
@@ -1108,7 +1108,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID)
   ProfileStatisticsFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ProfileTokenWebSigninInterceptorFactory::GetInstance();
   OidcAuthenticationSigninInterceptorFactory::GetInstance();
 #endif
@@ -1127,7 +1127,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #endif
   ReduceAcceptLanguageFactory::GetInstance();
   RendererUpdaterFactory::GetInstance();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   reporting::ManualTestHeartbeatEventFactory::GetInstance();
 #endif
 #if !BUILDFLAG(IS_ANDROID)
