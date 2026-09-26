--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -330,7 +330,7 @@
 #include "ui/webui/buildflags.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/enterprise/network_header_injection/core/features.h"  // nogncheck
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -441,7 +441,7 @@
 #endif
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/idle/idle_service_factory.h"
 #endif
 
@@ -491,7 +491,7 @@
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.h"
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.h"
 #include "chrome/browser/enterprise/network_header_injection/http_header_injection_service_factory.h"  // nogncheck
@@ -507,11 +507,11 @@
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
@@ -597,7 +597,7 @@
 #include "chrome/browser/sessions/session_service_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/gapis/gapis_service_factory.h"
 #include "components/gapis/features.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
@@ -743,7 +743,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if !BUILDFLAG(IS_ANDROID)
   AutoPictureInPictureHatsServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   AccountsPolicyManagerFactory::GetInstance();
   search_integrity::SearchIntegrityFactory::GetInstance();
 #endif
@@ -803,7 +803,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   autofill::AutofillOfferManagerFactory::GetInstance();
   autofill::AutofillOptimizationGuideDeciderFactory::GetInstance();
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   autofill::CrossTabCopyPasteTrackerFactory::GetInstance();
 #endif
   autofill::EntitySuppressionManagerFactory::GetInstance();
@@ -848,7 +848,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #endif
 #endif
   browser_actuator::BrowserActuatorServiceFactory::GetInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherServiceFactory::GetInstance();
 #endif
   browser_sync::UserEventServiceFactory::GetInstance();
@@ -915,7 +915,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   collaboration::comments::CommentsServiceFactory::GetInstance();
   collaboration::messaging::MessagingBackendServiceFactory::GetInstance();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   tab_groups::CollaborationMessagingObserverFactory::GetInstance();
 #endif
   commerce::ShoppingServiceFactory::GetInstance();
@@ -928,7 +928,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   contextual_tasks::ContextualTasksUiServiceFactory::GetInstance();
 
   ContentIndexProviderFactory::GetInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   glic::ContextualCueingServiceFactory::GetInstance();
 #endif
   ContextualSearchServiceFactory::GetInstance();
@@ -980,7 +980,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #endif
   enterprise_connectors::ConnectorsServiceFactory::GetInstance();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   enterprise_connectors::DeviceTrustConnectorServiceFactory::GetInstance();
   enterprise_connectors::DeviceTrustServiceFactory::GetInstance();
 #endif
@@ -989,7 +989,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   enterprise_connectors::ExtensionInstallEventRouterFactory::GetInstance();
   enterprise_connectors::ExtensionTelemetryEventRouterFactory::GetInstance();
 #endif
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENTERPRISE_LOCAL_CONTENT_ANALYSIS) &&                    \
     BUILDFLAG(SAFE_BROWSING_AVAILABLE)
   enterprise_connectors::LocalBinaryUploadServiceFactory::GetInstance();
@@ -1004,7 +1004,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   }
 #endif
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (enterprise_custom_headers::IsHttpHeaderInjectionEnabled()) {
     enterprise_custom_headers::HttpHeaderInjectionServiceFactory::GetInstance();
   }
@@ -1018,7 +1018,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   enterprise_groups::EnterpriseGroupsProfileHandlerFactory::GetInstance();
 #endif
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   enterprise_idle::IdleServiceFactory::GetInstance();
 #endif
   enterprise_isolated_mode::IsolatedModeSettingsServiceFactory::GetInstance();
@@ -1030,10 +1030,10 @@ void ChromeBrowserMainExtraPartsProfiles::
   enterprise_reporting::LegacyTechServiceFactory::GetInstance();
   enterprise_reporting::SaasUsageReportingControllerFactory::GetInstance();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   enterprise_signals::UserPermissionServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   enterprise_signin::EnterpriseSigninServiceFactory::GetInstance();
 #endif
 #if !BUILDFLAG(IS_ANDROID)
@@ -1083,7 +1083,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_CHROMEOS)
   GalleryWatchManager::EnsureFactoryBuilt();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(gapis::kEnableGapis)) {
     GapisServiceFactory::GetInstance();
   }
@@ -1176,7 +1176,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_ANDROID)
   MerchantViewerDataManagerFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
   private_insights::PrivateInsightsServiceFactory::GetInstance();
@@ -1294,7 +1294,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   PasswordCounterFactory::GetInstance();
 #endif  // !BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   PasswordManagerBlocklistPolicyFactory::GetInstance();
 #endif
   PasswordManagerSettingsServiceFactory::GetInstance();
@@ -1346,7 +1346,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_CHROMEOS)
   policy::PolicyCertServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   policy::ProfileTokenPolicyWebSigninServiceFactory::GetInstance();
 #endif
   policy::UserCloudPolicyInvalidatorFactory::GetInstance();
@@ -1356,7 +1356,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #else
   policy::UserPolicySigninServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   policy::UserPolicyOidcSigninServiceFactory::GetInstance();
 #endif
   PredictionModelHandlerProviderFactory::GetInstance();
@@ -1378,7 +1378,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS)
   ProfileStatisticsFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ProfileTokenWebSigninInterceptorFactory::GetInstance();
   OidcAuthenticationSigninInterceptorFactory::GetInstance();
 #endif
@@ -1400,7 +1400,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   ReduceAcceptLanguageFactory::GetInstance();
   RendererUpdaterFactory::GetInstance();
   regional_capabilities::RegionalCapabilitiesServiceFactory::GetInstance();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   reporting::ManualTestHeartbeatEventFactory::GetInstance();
 #endif
   RevokedPermissionsOSNotificationDisplayManagerFactory::GetInstance();
