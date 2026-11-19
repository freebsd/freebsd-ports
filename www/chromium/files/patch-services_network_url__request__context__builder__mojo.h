--- services/network/url_request_context_builder_mojo.h.orig	2026-11-19 12:25:27 UTC
+++ services/network/url_request_context_builder_mojo.h
@@ -14,7 +14,7 @@
 #include "services/network/url_request_context_owner.h"
 #include "services/proxy_resolver/public/mojom/proxy_resolver.mojom.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "services/proxy_resolver/public/mojom/system_proxy_resolver.mojom.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -59,7 +59,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) URLRequestCont
       mojo::PendingRemote<proxy_resolver::mojom::ProxyResolverFactory>
           mojo_proxy_resolver_factory);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetMojoSystemProxyResolver(
       mojo::PendingRemote<proxy_resolver::mojom::SystemProxyResolver>
           mojo_system_proxy_resolver);
@@ -101,7 +101,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) URLRequestCont
   mojo::PendingRemote<proxy_resolver::mojom::ProxyResolverFactory>
       mojo_proxy_resolver_factory_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   mojo::PendingRemote<proxy_resolver::mojom::SystemProxyResolver>
       mojo_system_proxy_resolver_;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
