--- source/extensions/filters/listener/tls_inspector/config.cc.orig	2023-04-27 12:00:08 UTC
+++ source/extensions/filters/listener/tls_inspector/config.cc
@@ -46,9 +46,7 @@ class TlsInspectorConfigFactory : public Server::Confi
 /**
  * Static registration for the TLS inspector filter. @see RegisterFactory.
  */
-REGISTER_FACTORY(TlsInspectorConfigFactory,
-                 Server::Configuration::NamedListenerFilterConfigFactory){
-    "envoy.listener.tls_inspector"};
+LEGACY_REGISTER_FACTORY(TlsInspectorConfigFactory, Server::Configuration::NamedListenerFilterConfigFactory, "envoy.listener.tls_inspector");
 
 } // namespace TlsInspector
 } // namespace ListenerFilters
