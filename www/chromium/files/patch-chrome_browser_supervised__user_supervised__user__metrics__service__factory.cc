--- chrome/browser/supervised_user/supervised_user_metrics_service_factory.cc.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/supervised_user/supervised_user_metrics_service_factory.cc
@@ -15,7 +15,7 @@
 #include "content/public/browser/browser_context.h"
 #include "chrome/browser/supervised_user/metrics_service_accessor_delegate.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/linux_mac_windows/supervised_user_extensions_metrics_delegate_impl.h"
 #endif
 
@@ -63,7 +63,7 @@ SupervisedUserMetricsServiceFactory::BuildServiceInsta
   std::unique_ptr<supervised_user::SupervisedUserMetricsService ::
                       SupervisedUserMetricsServiceExtensionDelegate>
       extensions_metrics_delegate = nullptr;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   extensions_metrics_delegate =
       std::make_unique<SupervisedUserExtensionsMetricsDelegateImpl>(
           extensions::ExtensionRegistry::Get(profile), profile);
