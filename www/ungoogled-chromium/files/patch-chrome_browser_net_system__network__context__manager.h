--- chrome/browser/net/system_network_context_manager.h.orig	2023-06-05 19:39:05 UTC
+++ chrome/browser/net/system_network_context_manager.h
@@ -207,7 +207,7 @@ class SystemNetworkContextManager {
 #endif  // BUILDFLAG(CHROME_ROOT_STORE_POLICY_SUPPORTED)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Applies the current value of the kEnforceLocalAnchorConstraintsEnabled
   // pref to the enforcement state.
   void UpdateEnforceLocalAnchorConstraintsEnabled();
