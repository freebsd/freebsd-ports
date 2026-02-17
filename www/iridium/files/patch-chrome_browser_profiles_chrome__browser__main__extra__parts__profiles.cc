--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2026-02-16 10:45:29 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -381,7 +381,7 @@
 #endif
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "chrome/browser/enterprise/client_certificates/certificate_store_factory.h"
 #include "chrome/browser/enterprise/idle/idle_service_factory.h"
@@ -429,7 +429,7 @@
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.h"
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.h"
 #include "chrome/browser/ui/tabs/saved_tab_groups/collaboration_messaging_observer_factory.h"
@@ -441,11 +441,11 @@
 #include "chrome/browser/webauthn/passkey_unlock_manager_factory.h"
 #include "device/fido/public/features.h"
 #endif
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/policy/messaging_layer/util/manual_test_heartbeat_event_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_service_factory.h"
 #include "chrome/browser/enterprise/signin/enterprise_signin_service_factory.h"
 #include "chrome/browser/enterprise/signin/oidc_authentication_signin_interceptor_factory.h"
@@ -662,7 +662,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   AccountPasswordStoreFactory::GetInstance();
   AccountReconcilorFactory::GetInstance();
   autofill::AccountSettingServiceFactory::GetInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   AccountsPolicyManagerFactory::GetInstance();
 #endif
 #if !BUILDFLAG(IS_ANDROID)
@@ -761,7 +761,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   DiceBoundSessionCookieServiceFactory::GetInstance();
 #endif
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherServiceFactory::GetInstance();
 #endif
   browser_sync::UserEventServiceFactory::GetInstance();
@@ -825,7 +825,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   collaboration::comments::CommentsServiceFactory::GetInstance();
   collaboration::messaging::MessagingBackendServiceFactory::GetInstance();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   tab_groups::CollaborationMessagingObserverFactory::GetInstance();
 #endif
   commerce::ShoppingServiceFactory::GetInstance();
@@ -838,7 +838,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   contextual_tasks::ContextualTasksUiServiceFactory::GetInstance();
 #endif
   ContentIndexProviderFactory::GetInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   contextual_cueing::ContextualCueingServiceFactory::GetInstance();
 #endif
   ContextualSearchServiceFactory::GetInstance();
@@ -891,11 +891,11 @@ void ChromeBrowserMainExtraPartsProfiles::
   enterprise_connectors::ConnectorsServiceFactory::GetInstance();
   enterprise_connectors::ReportingEventRouterFactory::GetInstance();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   enterprise_connectors::DeviceTrustConnectorServiceFactory::GetInstance();
   enterprise_connectors::DeviceTrustServiceFactory::GetInstance();
 #endif
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENTERPRISE_LOCAL_CONTENT_ANALYSIS) &&                    \
     BUILDFLAG(SAFE_BROWSING_AVAILABLE)
   enterprise_connectors::LocalBinaryUploadServiceFactory::GetInstance();
@@ -905,7 +905,7 @@ void ChromeBrowserMainExtraPartsProfiles::
       GetInstance();
 #endif
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   enterprise_idle::IdleServiceFactory::GetInstance();
   enterprise_signals::SignalsAggregatorFactory::GetInstance();
 #endif
@@ -914,10 +914,10 @@ void ChromeBrowserMainExtraPartsProfiles::
 #endif
   enterprise_reporting::LegacyTechServiceFactory::GetInstance();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   enterprise_signals::UserPermissionServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   enterprise_signin::EnterpriseSigninServiceFactory::GetInstance();
 #endif
 #if BUILDFLAG(ENABLE_SESSION_SERVICE)
@@ -1052,7 +1052,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_ANDROID)
   MerchantViewerDataManagerFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
 #if !BUILDFLAG(IS_ANDROID)
@@ -1144,7 +1144,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   PasswordCounterFactory::GetInstance();
 #endif  // !BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   PasswordManagerBlocklistPolicyFactory::GetInstance();
 #endif
   PasswordManagerSettingsServiceFactory::GetInstance();
@@ -1190,7 +1190,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_CHROMEOS)
   policy::PolicyCertServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   policy::ProfileTokenPolicyWebSigninServiceFactory::GetInstance();
 #endif
   policy::UserCloudPolicyInvalidatorFactory::GetInstance();
@@ -1200,7 +1200,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #else
   policy::UserPolicySigninServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   policy::UserPolicyOidcSigninServiceFactory::GetInstance();
 #endif
   PredictionModelHandlerProviderFactory::GetInstance();
@@ -1227,7 +1227,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS)
   ProfileStatisticsFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ProfileTokenWebSigninInterceptorFactory::GetInstance();
   OidcAuthenticationSigninInterceptorFactory::GetInstance();
 #endif
@@ -1244,7 +1244,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   ReduceAcceptLanguageFactory::GetInstance();
   RendererUpdaterFactory::GetInstance();
   regional_capabilities::RegionalCapabilitiesServiceFactory::GetInstance();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   reporting::ManualTestHeartbeatEventFactory::GetInstance();
 #endif
   RevokedPermissionsOSNotificationDisplayManagerFactory::GetInstance();
