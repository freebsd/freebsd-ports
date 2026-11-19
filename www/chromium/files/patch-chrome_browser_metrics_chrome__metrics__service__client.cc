--- chrome/browser/metrics/chrome_metrics_service_client.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/metrics/chrome_metrics_service_client.cc
@@ -208,7 +208,7 @@
 #include "chrome/browser/metrics/task_info_metrics_provider_mac.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/metrics/motherboard_metrics_provider.h"
 #endif
 
@@ -220,7 +220,7 @@
 #include "chrome/browser/metrics/bluetooth_metrics_provider.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/updates/update_metrics_provider.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -593,7 +593,7 @@ void ChromeMetricsServiceClient::RegisterPrefs(PrefReg
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   metrics::structured::StructuredMetricsService::RegisterPrefs(registry);
 
 #if !BUILDFLAG(IS_CHROMEOS)
@@ -797,7 +797,7 @@ void ChromeMetricsServiceClient::Initialize() {
         this, local_state);
   }
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   metrics::structured::Recorder::GetInstance()->SetUiTaskRunner(
       base::SequencedTaskRunner::GetCurrentDefault());
 #endif
@@ -857,7 +857,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<metrics::CPUMetricsProvider>());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<metrics::MotherboardMetricsProvider>());
 #endif
@@ -964,7 +964,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<DesktopPlatformFeaturesMetricsProvider>());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -1072,7 +1072,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
       std::make_unique<PowerMetricsProvider>());
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       metrics::CreateDesktopSessionMetricsProvider());
   metrics_service_->RegisterMetricsProvider(
@@ -1296,7 +1296,7 @@ bool ChromeMetricsServiceClient::RegisterForProfileEve
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This creates the DesktopProfileSessionDurationsServices if it didn't exist
   // already.
   metrics::DesktopProfileSessionDurationsServiceFactory::GetForBrowserContext(
@@ -1691,7 +1691,7 @@ void ChromeMetricsServiceClient::CreateStructuredMetri
   recorder =
       std::make_unique<metrics::structured::AshStructuredMetricsRecorder>(
           cros_system_profile_provider_.get());
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
   // Make sure that Structured Metrics recording delegates have been created
   // before the service is created. This is handled in other places for ChromeOS
