--- chrome/browser/net/system_network_context_manager.h.orig	2024-03-22 14:16:19 UTC
+++ chrome/browser/net/system_network_context_manager.h
@@ -204,7 +204,7 @@ class SystemNetworkContextManager {
   class URLLoaderFactoryForSystem;
   class NetworkProcessLaunchWatcher;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   class GssapiLibraryLoadObserver
       : public network::mojom::GssapiLibraryLoadObserver {
    public:
@@ -240,7 +240,7 @@ class SystemNetworkContextManager {
   void UpdateExplicitlyAllowedNetworkPorts();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Applies the current value of the kEnforceLocalAnchorConstraintsEnabled
   // pref to the enforcement state.
   void UpdateEnforceLocalAnchorConstraintsEnabled();
@@ -290,7 +290,7 @@ class SystemNetworkContextManager {
 
   std::unique_ptr<NetworkAnnotationMonitor> network_annotation_monitor_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   GssapiLibraryLoadObserver gssapi_library_loader_observer_{this};
 #endif  // BUILDFLAG(IS_LINUX)
 
