--- chrome/browser/ui/tabs/public/tab_features.h.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/ui/tabs/public/tab_features.h
@@ -147,7 +147,7 @@ class TabContextualizationController;
 }  // namespace lens
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace wallet {
 class ChromeWalletablePassClient;
 }  // namespace wallet
@@ -540,7 +540,7 @@ class TabFeatures {
       skills_ui_tab_controller_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<wallet::ChromeWalletablePassClient> walletable_pass_client_;
 #endif
 
@@ -551,7 +551,7 @@ class TabFeatures {
   std::unique_ptr<skills::SkillsUpdateObserver> skills_update_observer_;
 #endif  // BUILDFLAG(ENABLE_GLIC) && !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<enterprise_reporting::SaasUsageNavigationObserver>
       saas_usage_navigation_observer_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
