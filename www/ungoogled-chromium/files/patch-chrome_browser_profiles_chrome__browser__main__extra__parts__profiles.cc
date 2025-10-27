--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2025-10-21 16:57:35 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -377,7 +377,7 @@
 #endif
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "chrome/browser/enterprise/client_certificates/certificate_store_factory.h"
 #include "chrome/browser/enterprise/idle/idle_service_factory.h"
@@ -423,14 +423,14 @@
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.h"
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.h"
 #include "chrome/browser/ui/tabs/saved_tab_groups/collaboration_messaging_observer_factory.h"
 #include "chrome/browser/ui/tabs/saved_tab_groups/saved_tab_group_utils.h"
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/policy/messaging_layer/util/manual_test_heartbeat_event_factory.h"
 #endif
 
@@ -438,7 +438,7 @@
 #include "chrome/browser/history_embeddings/history_embeddings_service_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_service_factory.h"
 #include "chrome/browser/enterprise/signin/enterprise_signin_service_factory.h"
 #include "chrome/browser/enterprise/signin/oidc_authentication_signin_interceptor_factory.h"
@@ -663,7 +663,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   AccountInvestigatorFactory::GetInstance();
   AccountPasswordStoreFactory::GetInstance();
   AccountReconcilorFactory::GetInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   AccountsPolicyManagerFactory::GetInstance();
 #endif
 #if !BUILDFLAG(IS_ANDROID)
@@ -762,7 +762,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   DiceBoundSessionCookieServiceFactory::GetInstance();
 #endif
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherServiceFactory::GetInstance();
 #endif
   browser_sync::UserEventServiceFactory::GetInstance();
@@ -825,13 +825,13 @@ void ChromeBrowserMainExtraPartsProfiles::
   collaboration::comments::CommentsServiceFactory::GetInstance();
   collaboration::messaging::MessagingBackendServiceFactory::GetInstance();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   tab_groups::CollaborationMessagingObserverFactory::GetInstance();
 #endif
   commerce::ShoppingServiceFactory::GetInstance();
   ConsentAuditorFactory::GetInstance();
   ContentIndexProviderFactory::GetInstance();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   contextual_cueing::ContextualCueingServiceFactory::GetInstance();
 #endif
   CookieSettingsFactory::GetInstance();
@@ -881,17 +881,17 @@ void ChromeBrowserMainExtraPartsProfiles::
 #endif
   enterprise_connectors::ConnectorsServiceFactory::GetInstance();
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
 #endif
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   enterprise_idle::IdleServiceFactory::GetInstance();
   enterprise_signals::SignalsAggregatorFactory::GetInstance();
 #endif
@@ -900,10 +900,10 @@ void ChromeBrowserMainExtraPartsProfiles::
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
@@ -1043,7 +1043,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_ANDROID)
   MerchantViewerDataManagerFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
 #if !BUILDFLAG(IS_ANDROID)
@@ -1126,7 +1126,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   PasswordCounterFactory::GetInstance();
 #endif  // !BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   PasswordManagerBlocklistPolicyFactory::GetInstance();
 #endif
   PasswordManagerSettingsServiceFactory::GetInstance();
@@ -1171,7 +1171,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if BUILDFLAG(IS_CHROMEOS)
   policy::PolicyCertServiceFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   policy::ProfileTokenPolicyWebSigninServiceFactory::GetInstance();
   policy::UserPolicyOidcSigninServiceFactory::GetInstance();
 #endif
@@ -1207,7 +1207,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS)
   ProfileStatisticsFactory::GetInstance();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ProfileTokenWebSigninInterceptorFactory::GetInstance();
   OidcAuthenticationSigninInterceptorFactory::GetInstance();
 #endif
@@ -1227,7 +1227,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   ReduceAcceptLanguageFactory::GetInstance();
   RendererUpdaterFactory::GetInstance();
   regional_capabilities::RegionalCapabilitiesServiceFactory::GetInstance();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   reporting::ManualTestHeartbeatEventFactory::GetInstance();
 #endif
 #if !BUILDFLAG(IS_ANDROID)
