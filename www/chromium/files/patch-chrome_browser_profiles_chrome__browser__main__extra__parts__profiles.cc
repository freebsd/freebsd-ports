--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2026-01-14 08:33:23 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -385,7 +385,7 @@
 #endif
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "chrome/browser/enterprise/client_certificates/certificate_store_factory.h"
 #include "chrome/browser/enterprise/idle/idle_service_factory.h"
@@ -430,7 +430,7 @@
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.h"
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.h"
 #include "chrome/browser/ui/tabs/saved_tab_groups/collaboration_messaging_observer_factory.h"
@@ -442,11 +442,11 @@
 #include "chrome/browser/webauthn/passkey_unlock_manager_factory.h"
 #include "device/fido/features.h"
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
@@ -672,7 +672,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   AccountPasswordStoreFactory::GetInstance();
   AccountReconcilorFactory::GetInstance();
   autofill::AccountSettingServiceFactory::GetInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   AccountsPolicyManagerFactory::GetInstance();
 #endif
 #if !BUILDFLAG(IS_ANDROID)
@@ -771,7 +771,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   DiceBoundSessionCookieServiceFactory::GetInstance();
 #endif
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherServiceFactory::GetInstance();
 #endif
   browser_sync::UserEventServiceFactory::GetInstance();
@@ -835,7 +835,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   collaboration::comments::CommentsServiceFactory::GetInstance();
   collaboration::messaging::MessagingBackendServiceFactory::GetInstance();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   tab_groups::CollaborationMessagingObserverFactory::GetInstance();
 #endif
   commerce::ShoppingServiceFactory::GetInstance();
@@ -848,7 +848,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   contextual_tasks::ContextualTasksUiServiceFactory::GetInstance();
 #endif
   ContentIndexProviderFactory::GetInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   contextual_cueing::ContextualCueingServiceFactory::GetInstance();
 #endif
   ContextualSearchServiceFactory::GetInstance();
@@ -902,11 +902,11 @@ void ChromeBrowserMainExtraPartsProfiles::
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
@@ -916,7 +916,7 @@ void ChromeBrowserMainExtraPartsProfiles::
       GetInstance();
 #endif
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   enterprise_idle::IdleServiceFactory::GetInstance();
   enterprise_signals::SignalsAggregatorFactory::GetInstance();
 #endif
@@ -925,10 +925,10 @@ void ChromeBrowserMainExtraPartsProfiles::
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
@@ -1063,7 +1063,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_ANDROID)
   MerchantViewerDataManagerFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
 #if !BUILDFLAG(IS_ANDROID)
@@ -1155,7 +1155,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   PasswordCounterFactory::GetInstance();
 #endif  // !BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   PasswordManagerBlocklistPolicyFactory::GetInstance();
 #endif
   PasswordManagerSettingsServiceFactory::GetInstance();
@@ -1201,7 +1201,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_CHROMEOS)
   policy::PolicyCertServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   policy::ProfileTokenPolicyWebSigninServiceFactory::GetInstance();
   policy::UserPolicyOidcSigninServiceFactory::GetInstance();
 #endif
@@ -1236,7 +1236,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS)
   ProfileStatisticsFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ProfileTokenWebSigninInterceptorFactory::GetInstance();
   OidcAuthenticationSigninInterceptorFactory::GetInstance();
 #endif
@@ -1256,7 +1256,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   ReduceAcceptLanguageFactory::GetInstance();
   RendererUpdaterFactory::GetInstance();
   regional_capabilities::RegionalCapabilitiesServiceFactory::GetInstance();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   reporting::ManualTestHeartbeatEventFactory::GetInstance();
 #endif
   RevokedPermissionsOSNotificationDisplayManagerFactory::GetInstance();
