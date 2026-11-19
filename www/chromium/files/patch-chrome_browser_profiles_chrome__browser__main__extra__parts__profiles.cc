--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -434,7 +434,7 @@
 #endif
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/idle/idle_service_factory.h"
 #endif
 
@@ -486,7 +486,7 @@
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.h"
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/tabs/saved_tab_groups/collaboration_messaging_observer_factory.h"
 #endif
 
@@ -500,11 +500,11 @@
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
@@ -594,7 +594,7 @@
 #include "chrome/browser/sessions/session_service_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/gapis/gapis_service_factory.h"
 #include "components/gapis/features.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
@@ -736,7 +736,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if !BUILDFLAG(IS_ANDROID)
   AutoPictureInPictureHatsServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   AccountsPolicyManagerFactory::GetInstance();
   search_integrity::SearchIntegrityFactory::GetInstance();
 #endif
@@ -796,7 +796,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   autofill::AutofillOfferManagerFactory::GetInstance();
   autofill::AutofillOptimizationGuideDeciderFactory::GetInstance();
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   autofill::CrossTabCopyPasteTrackerFactory::GetInstance();
 #endif
   autofill::EntitySuppressionManagerFactory::GetInstance();
@@ -841,7 +841,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #endif
   browser_actuator::BrowserActuatorServiceFactory::GetInstance();
   browser_actuator::transport::TransportServiceFactory::GetInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherServiceFactory::GetInstance();
 #endif
 #if !BUILDFLAG(IS_ANDROID)
@@ -896,7 +896,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   collaboration::comments::CommentsServiceFactory::GetInstance();
   collaboration::messaging::MessagingBackendServiceFactory::GetInstance();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   tab_groups::CollaborationMessagingObserverFactory::GetInstance();
 #endif
   commerce::ShoppingServiceFactory::GetInstance();
@@ -910,7 +910,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   contextual_tasks::SearchJourneyTrackerFactory::GetInstance();
 
   ContentIndexProviderFactory::GetInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   glic::ContextualCueingServiceFactory::GetInstance();
 #endif
   ContextualSearchServiceFactory::GetInstance();
@@ -972,7 +972,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   enterprise_connectors::ExtensionInstallEventRouterFactory::GetInstance();
   enterprise_connectors::ExtensionTelemetryEventRouterFactory::GetInstance();
 #endif
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENTERPRISE_LOCAL_CONTENT_ANALYSIS) &&                    \
     BUILDFLAG(SAFE_BROWSING_AVAILABLE)
   enterprise_connectors::LocalBinaryUploadServiceFactory::GetInstance();
@@ -993,7 +993,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   enterprise_groups::EnterpriseGroupsProfileHandlerFactory::GetInstance();
 #endif
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   enterprise_idle::IdleServiceFactory::GetInstance();
 #endif
   enterprise_isolated_mode::IsolatedModeSettingsServiceFactory::GetInstance();
@@ -1005,10 +1005,10 @@ void ChromeBrowserMainExtraPartsProfiles::
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
@@ -1059,7 +1059,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_CHROMEOS)
   GalleryWatchManager::EnsureFactoryBuilt();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(gapis::kEnableGapis)) {
     GapisServiceFactory::GetInstance();
   }
@@ -1152,7 +1152,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_ANDROID)
   MerchantViewerDataManagerFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
   private_insights::PrivateInsightsServiceFactory::GetInstance();
@@ -1261,7 +1261,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   PasswordChangeServiceFactory::GetInstance();
   PasswordCounterFactory::GetInstance();
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   PasswordManagerBlocklistPolicyFactory::GetInstance();
 #endif
   PasswordManagerSettingsServiceFactory::GetInstance();
@@ -1313,7 +1313,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_CHROMEOS)
   policy::PolicyCertServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   policy::ProfileTokenPolicyWebSigninServiceFactory::GetInstance();
 #endif
   policy::UserCloudPolicyInvalidatorFactory::GetInstance();
@@ -1323,7 +1323,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #else
   policy::UserPolicySigninServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   policy::UserPolicyOidcSigninServiceFactory::GetInstance();
 #endif
   PredictionModelHandlerProviderFactory::GetInstance();
@@ -1345,7 +1345,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS)
   ProfileStatisticsFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ProfileTokenWebSigninInterceptorFactory::GetInstance();
   OidcAuthenticationSigninInterceptorFactory::GetInstance();
 #endif
@@ -1367,7 +1367,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   ReduceAcceptLanguageFactory::GetInstance();
   RendererUpdaterFactory::GetInstance();
   regional_capabilities::RegionalCapabilitiesServiceFactory::GetInstance();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   reporting::ManualTestHeartbeatEventFactory::GetInstance();
 #endif
   RevokedPermissionsOSNotificationDisplayManagerFactory::GetInstance();
