--- source/extensions/filters/listener/original_src/original_src_config_factory.cc.orig	2023-04-27 12:00:08 UTC
+++ source/extensions/filters/listener/original_src/original_src_config_factory.cc
@@ -32,8 +32,7 @@ ProtobufTypes::MessagePtr OriginalSrcConfigFactory::cr
 /**
  * Static registration for the original_src filter. @see RegisterFactory.
  */
-REGISTER_FACTORY(OriginalSrcConfigFactory, Server::Configuration::NamedListenerFilterConfigFactory){
-    "envoy.listener.original_src"};
+LEGACY_REGISTER_FACTORY(OriginalSrcConfigFactory, Server::Configuration::NamedListenerFilterConfigFactory, "envoy.listener.original_src");
 
 } // namespace OriginalSrc
 } // namespace ListenerFilters
