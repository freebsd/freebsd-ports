--- source/extensions/filters/listener/original_dst/config.cc.orig	2023-04-27 12:00:08 UTC
+++ source/extensions/filters/listener/original_dst/config.cc
@@ -56,8 +56,7 @@ class OriginalDstConfigFactory : public Server::Config
 /**
  * Static registration for the original dst filter. @see RegisterFactory.
  */
-REGISTER_FACTORY(OriginalDstConfigFactory, Server::Configuration::NamedListenerFilterConfigFactory){
-    "envoy.listener.original_dst"};
+LEGACY_REGISTER_FACTORY(OriginalDstConfigFactory, Server::Configuration::NamedListenerFilterConfigFactory, "envoy.listener.original_dst");
 
 } // namespace OriginalDst
 } // namespace ListenerFilters
