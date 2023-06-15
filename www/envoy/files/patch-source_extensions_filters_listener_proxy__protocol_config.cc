--- source/extensions/filters/listener/proxy_protocol/config.cc.orig	2023-04-27 12:00:08 UTC
+++ source/extensions/filters/listener/proxy_protocol/config.cc
@@ -46,9 +46,7 @@ class ProxyProtocolConfigFactory : public Server::Conf
 /**
  * Static registration for the proxy protocol filter. @see RegisterFactory.
  */
-REGISTER_FACTORY(ProxyProtocolConfigFactory,
-                 Server::Configuration::NamedListenerFilterConfigFactory){
-    "envoy.listener.proxy_protocol"};
+LEGACY_REGISTER_FACTORY(ProxyProtocolConfigFactory, Server::Configuration::NamedListenerFilterConfigFactory, "envoy.listener.proxy_protocol");
 
 } // namespace ProxyProtocol
 } // namespace ListenerFilters
