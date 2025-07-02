--- services/network/network_context.cc.orig	2025-07-02 06:08:04 UTC
+++ services/network/network_context.cc
@@ -611,7 +611,7 @@ NetworkContext::NetworkContextHttpAuthPreferences::
 NetworkContext::NetworkContextHttpAuthPreferences::
     ~NetworkContextHttpAuthPreferences() = default;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool NetworkContext::NetworkContextHttpAuthPreferences::AllowGssapiLibraryLoad()
     const {
   if (network_service_) {
@@ -2556,7 +2556,7 @@ void NetworkContext::OnHttpAuthDynamicParamsChanged(
       http_auth_dynamic_network_service_params->android_negotiate_account_type);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   http_auth_merged_preferences_.set_allow_gssapi_library_load(
       http_auth_dynamic_network_service_params->allow_gssapi_library_load);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
