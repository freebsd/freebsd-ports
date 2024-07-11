--- device/fido/fido_discovery_factory.cc.orig	2024-06-17 12:56:06 UTC
+++ device/fido/fido_discovery_factory.cc
@@ -127,7 +127,7 @@ std::vector<std::unique_ptr<FidoDiscoveryBase>> FidoDi
 
 std::optional<std::unique_ptr<FidoDiscoveryBase>>
 FidoDiscoveryFactory::MaybeCreateEnclaveDiscovery() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(kWebAuthnEnclaveAuthenticator) ||
       !enclave_ui_request_stream_ || !network_context_factory_) {
     return std::nullopt;
