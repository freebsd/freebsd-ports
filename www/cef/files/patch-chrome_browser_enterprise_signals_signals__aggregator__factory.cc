--- chrome/browser/enterprise/signals/signals_aggregator_factory.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/enterprise/signals/signals_aggregator_factory.cc
@@ -63,7 +63,7 @@
 #include "components/device_signals/core/browser/settings_client.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/agent_signals_collector.h"
 #include "components/device_signals/core/browser/crowdstrike_client.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -103,7 +103,7 @@ SignalsAggregatorFactory::SignalsAggregatorFactory()
   DependsOn(UserPermissionServiceFactory::GetInstance());
   DependsOn(enterprise::ProfileIdServiceFactory::GetInstance());
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   DependsOn(ProfileNetworkContextServiceFactory::GetInstance());
 #endif
 }
@@ -131,7 +131,7 @@ SignalsAggregatorFactory::BuildServiceInstanceForBrows
           service_host));
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   collectors.push_back(std::make_unique<device_signals::AgentSignalsCollector>(
       device_signals::CrowdStrikeClient::Create()));
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -143,7 +143,7 @@ SignalsAggregatorFactory::BuildServiceInstanceForBrows
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (enterprise_signals::features::IsCertificateCollectionEnabled()) {
     auto* profile_network_service =
         ProfileNetworkContextServiceFactory::GetForContext(profile);
