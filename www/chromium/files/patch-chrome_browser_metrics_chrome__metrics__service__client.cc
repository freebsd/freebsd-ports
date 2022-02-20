--- chrome/browser/metrics/chrome_metrics_service_client.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/metrics/chrome_metrics_service_client.cc
@@ -742,7 +742,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<DesktopPlatformFeaturesMetricsProvider>());
@@ -838,7 +838,7 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
       std::make_unique<PowerMetricsProvider>());
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
   metrics_service_->RegisterMetricsProvider(
       metrics::CreateDesktopSessionMetricsProvider());
 #endif  // defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX)
@@ -1014,7 +1014,7 @@ bool ChromeMetricsServiceClient::RegisterForProfileEve
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   // This creates the DesktopProfileSessionDurationsServices if it didn't exist
   // already.
