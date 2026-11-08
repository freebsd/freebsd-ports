--- chrome/browser/ui/tabs/public/tab_features.h.orig	2026-10-31 12:09:36 UTC
+++ chrome/browser/ui/tabs/public/tab_features.h
@@ -255,14 +255,14 @@ namespace lens {
 class TabContextualizationController;
 }  // namespace lens
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace metrics {
 class DesktopSessionDurationObserver;
 }  // namespace metrics
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace wallet {
 class ChromeWalletablePassClient;
 }  // namespace wallet
@@ -766,20 +766,20 @@ class TabFeatures {
       page_context_eligibility_helper_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<wallet::ChromeWalletablePassClient> walletable_pass_client_;
 #endif
 
   std::unique_ptr<contextual_tasks::ContextualTasksTabVisitTracker>
       contextual_tasks_tab_visit_tracker_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<metrics::DesktopSessionDurationObserver>
       desktop_session_duration_observer_;
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<enterprise_reporting::SaasUsageNavigationObserver>
       saas_usage_navigation_observer_;
   std::unique_ptr<HatsHelper> hats_helper_;
