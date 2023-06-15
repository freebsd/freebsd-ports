--- source/extensions/filters/listener/http_inspector/config.cc.orig	2023-04-27 12:00:08 UTC
+++ source/extensions/filters/listener/http_inspector/config.cc
@@ -38,9 +38,7 @@ class HttpInspectorConfigFactory : public Server::Conf
 /**
  * Static registration for the http inspector filter. @see RegisterFactory.
  */
-REGISTER_FACTORY(HttpInspectorConfigFactory,
-                 Server::Configuration::NamedListenerFilterConfigFactory){
-    "envoy.listener.http_inspector"};
+LEGACY_REGISTER_FACTORY(HttpInspectorConfigFactory, Server::Configuration::NamedListenerFilterConfigFactory, "envoy.listener.http_inspector");
 
 } // namespace HttpInspector
 } // namespace ListenerFilters
