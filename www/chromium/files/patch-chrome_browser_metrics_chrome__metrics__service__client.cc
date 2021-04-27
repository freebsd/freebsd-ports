--- chrome/browser/metrics/chrome_metrics_service_client.cc.orig	2021-04-14 18:40:53 UTC
+++ chrome/browser/metrics/chrome_metrics_service_client.cc
@@ -707,10 +707,10 @@ void ChromeMetricsServiceClient::RegisterMetricsServic
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<DesktopPlatformFeaturesMetricsProvider>());
-#endif  // defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS))
 
 #if BUILDFLAG(ENABLE_PLUGINS)
@@ -998,7 +998,7 @@ bool ChromeMetricsServiceClient::RegisterForProfileEve
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   // This creates the DesktopProfileSessionDurationsServices if it didn't exist
   // already.
   metrics::DesktopProfileSessionDurationsServiceFactory::GetForBrowserContext(
