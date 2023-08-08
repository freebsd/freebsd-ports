--- chrome/browser/enterprise/connectors/connectors_manager.h.orig	2023-07-21 09:49:17 UTC
+++ chrome/browser/enterprise/connectors/connectors_manager.h
@@ -16,7 +16,7 @@
 #include "third_party/abseil-cpp/absl/types/optional.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_list_observer.h"
 #include "chrome/browser/ui/tabs/tab_strip_model_observer.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -31,7 +31,7 @@ class BrowserCrashEventRouter;
 // Manages access to Connector policies for a given profile. This class is
 // responsible for caching the Connector policies, validate them against
 // approved service providers and provide a simple interface to them.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class ConnectorsManager : public BrowserListObserver,
                           public TabStripModelObserver {
 #else
@@ -51,7 +51,7 @@ class ConnectorsManager {
       PrefService* pref_service,
       const ServiceProviderConfig* config,
       bool observe_prefs = true);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ~ConnectorsManager() override;
 #else
   ~ConnectorsManager();
@@ -81,7 +81,7 @@ class ConnectorsManager {
   bool IsConnectorEnabled(AnalysisConnector connector) const;
   bool IsConnectorEnabled(ReportingConnector connector) const;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check if the corresponding connector is enabled for any local agent.
   bool IsConnectorEnabledForLocalAgent(AnalysisConnector connector) const;
 #endif
@@ -109,7 +109,7 @@ class ConnectorsManager {
       const;
 
  private:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // BrowserListObserver overrides:
   void OnBrowserAdded(Browser* browser) override;
   void OnBrowserRemoved(Browser* browser) override;
@@ -132,7 +132,7 @@ class ConnectorsManager {
   void CacheAnalysisConnectorPolicy(AnalysisConnector connector) const;
   void CacheReportingConnectorPolicy(ReportingConnector connector);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Close connection with local agent if all the relevant connectors are turned
   // off for it.
   void MaybeCloseLocalContentAnalysisAgentConnection();
