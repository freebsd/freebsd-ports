--- chrome/browser/net/system_network_context_manager.h.orig	2023-04-22 17:45:15 UTC
+++ chrome/browser/net/system_network_context_manager.h
@@ -194,7 +194,7 @@ class SystemNetworkContextManager {
   void UpdateExplicitlyAllowedNetworkPorts();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Applies the current value of the kEnforceLocalAnchorConstraintsEnabled
   // pref to the enforcement state.
   void UpdateEnforceLocalAnchorConstraintsEnabled();
