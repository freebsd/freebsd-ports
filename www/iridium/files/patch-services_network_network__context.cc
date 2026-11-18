--- services/network/network_context.cc.orig	2026-11-17 21:17:00 UTC
+++ services/network/network_context.cc
@@ -676,7 +676,7 @@ NetworkContext::NetworkContextHttpAuthPreferences::
 NetworkContext::NetworkContextHttpAuthPreferences::
     ~NetworkContextHttpAuthPreferences() = default;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool NetworkContext::NetworkContextHttpAuthPreferences::AllowGssapiLibraryLoad()
     const {
   if (network_service_) {
@@ -2836,7 +2836,7 @@ void NetworkContext::OnHttpAuthDynamicParamsChanged(
       http_auth_dynamic_network_service_params->android_negotiate_account_type);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   http_auth_merged_preferences_.set_allow_gssapi_library_load(
       http_auth_dynamic_network_service_params->allow_gssapi_library_load);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -2982,7 +2982,7 @@ URLRequestContextOwner NetworkContext::MakeURLRequestC
         std::move(params_->proxy_resolver_factory));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (params_->system_proxy_resolver) {
     builder.SetMojoSystemProxyResolver(
         std::move(params_->system_proxy_resolver));
