--- chrome/browser/enterprise/signals/signals_aggregator_factory.cc.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/enterprise/signals/signals_aggregator_factory.cc
@@ -54,7 +54,7 @@
 #include "components/device_signals/core/browser/settings_client.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/agent_signals_collector.h"
 #include "components/device_signals/core/browser/crowdstrike_client.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -93,7 +93,7 @@ SignalsAggregatorFactory::SignalsAggregatorFactory()
 #endif  // !BUILDFLAG(IS_ANDROID)
   DependsOn(UserPermissionServiceFactory::GetInstance());
   DependsOn(enterprise::ProfileIdServiceFactory::GetInstance());
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DependsOn(ProfileNetworkContextServiceFactory::GetInstance());
 #endif
 }
@@ -121,7 +121,7 @@ SignalsAggregatorFactory::BuildServiceInstanceForBrows
           service_host));
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   collectors.push_back(std::make_unique<device_signals::AgentSignalsCollector>(
       device_signals::CrowdStrikeClient::Create()));
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -132,7 +132,7 @@ SignalsAggregatorFactory::BuildServiceInstanceForBrows
           CreateSettingsClient()));
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (enterprise_signals::features::IsCertificateCollectionEnabled()) {
     auto* profile_network_service =
         ProfileNetworkContextServiceFactory::GetForContext(profile);
