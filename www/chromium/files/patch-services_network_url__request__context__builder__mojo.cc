--- services/network/url_request_context_builder_mojo.cc.orig	2026-11-19 12:25:27 UTC
+++ services/network/url_request_context_builder_mojo.cc
@@ -19,7 +19,7 @@
 #elif BUILDFLAG(IS_MAC)
 #include "net/proxy_resolution/mac/mac_system_proxy_resolution_service.h"
 #include "services/network/mac_system_proxy_resolver_mojo.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "net/proxy_resolution/linux/linux_system_proxy_resolution_service.h"
 #include "services/network/linux_system_proxy_resolver_mojo.h"
 #elif BUILDFLAG(IS_CHROMEOS)
@@ -39,7 +39,7 @@ void URLRequestContextBuilderMojo::SetMojoProxyResolve
   mojo_proxy_resolver_factory_ = std::move(mojo_proxy_resolver_factory);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void URLRequestContextBuilderMojo::SetMojoSystemProxyResolver(
     mojo::PendingRemote<proxy_resolver::mojom::SystemProxyResolver>
         mojo_system_proxy_resolver) {
@@ -106,7 +106,7 @@ URLRequestContextBuilderMojo::CreateProxyResolutionSer
   if (auto system_service = CreateSystemProxyResolutionService(net_log)) {
     return system_service;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (mojo_system_proxy_resolver_) {
     std::unique_ptr<net::ProxyResolutionService> proxy_resolution_service =
         net::LinuxSystemProxyResolutionService::Create(
