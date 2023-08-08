--- chrome/browser/enterprise/connectors/connectors_manager.cc.orig	2023-07-16 15:47:57 UTC
+++ chrome/browser/enterprise/connectors/connectors_manager.cc
@@ -16,7 +16,7 @@
 #include "components/prefs/pref_service.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/analysis/content_analysis_sdk_manager.h"  // nogncheck
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_list.h"
@@ -25,7 +25,7 @@
 
 namespace enterprise_connectors {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace {
 
 static constexpr enterprise_connectors::AnalysisConnector
@@ -51,7 +51,7 @@ ConnectorsManager::ConnectorsManager(
   DCHECK(browser_crash_event_router_) << "Crash event router is null";
   DCHECK(extension_install_event_router_) << "Extension event router is null";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Start observing tab strip models for all browsers.
   BrowserList* browser_list = BrowserList::GetInstance();
   for (Browser* browser : *browser_list) {
@@ -62,14 +62,14 @@ ConnectorsManager::ConnectorsManager(
 
   if (observe_prefs) {
     StartObservingPrefs(pref_service);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     MaybeCloseLocalContentAnalysisAgentConnection();
 #endif
   }
   extension_install_event_router_->StartObserving();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 ConnectorsManager::~ConnectorsManager() {
   BrowserList* browser_list = BrowserList::GetInstance();
   browser_list->RemoveObserver(this);
@@ -99,7 +99,7 @@ bool ConnectorsManager::IsConnectorEnabled(AnalysisCon
          base::FeatureList::IsEnabled(kLocalContentAnalysisEnabled);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool ConnectorsManager::IsConnectorEnabledForLocalAgent(
     AnalysisConnector connector) const {
   if (!IsConnectorEnabled(connector)) {
@@ -178,7 +178,7 @@ absl::optional<AnalysisSettings> ConnectorsManager::Ge
 }
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ConnectorsManager::OnBrowserAdded(Browser* browser) {
   browser->tab_strip_model()->AddObserver(this);
 }
@@ -241,7 +241,7 @@ void ConnectorsManager::CacheAnalysisConnectorPolicy(
         service_settings, *service_provider_config_);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ConnectorsManager::MaybeCloseLocalContentAnalysisAgentConnection() {
   for (auto connector : kLocalAnalysisConnectors) {
     if (IsConnectorEnabledForLocalAgent(connector)) {
@@ -257,7 +257,7 @@ void ConnectorsManager::MaybeCloseLocalContentAnalysis
 
 void ConnectorsManager::OnPrefChanged(AnalysisConnector connector) {
   CacheAnalysisConnectorPolicy(connector);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MaybeCloseLocalContentAnalysisAgentConnection();
 #endif
 }
