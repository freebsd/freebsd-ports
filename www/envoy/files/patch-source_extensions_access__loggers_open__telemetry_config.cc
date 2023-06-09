--- source/extensions/access_loggers/open_telemetry/config.cc.orig	2023-04-27 12:00:08 UTC
+++ source/extensions/access_loggers/open_telemetry/config.cc
@@ -63,8 +63,7 @@ std::string AccessLogFactory::name() const { return "e
 /**
  * Static registration for the OpenTelemetry (gRPC) access log. @see RegisterFactory.
  */
-REGISTER_FACTORY(AccessLogFactory, Server::Configuration::AccessLogInstanceFactory){
-    "envoy.open_telemetry_access_log"};
+LEGACY_REGISTER_FACTORY(AccessLogFactory, Server::Configuration::AccessLogInstanceFactory, "envoy.open_telemetry_access_log");
 
 } // namespace OpenTelemetry
 } // namespace AccessLoggers
