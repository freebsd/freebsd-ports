--- override/include/websocketpp/transport/asio/endpoint.hpp.orig	2016-10-09 22:39:45 UTC
+++ override/include/websocketpp/transport/asio/endpoint.hpp
@@ -491,7 +491,7 @@ public:
      * @param ec Set to indicate what error occurred, if any.
      */
     void listen(uint16_t port, lib::error_code & ec) {
-        listen(lib::asio::ip::tcp::v6(), port, ec);
+        listen(lib::asio::ip::tcp::v4(), port, ec);
     }
 
     /// Set up endpoint for listening on a port
@@ -507,7 +507,7 @@ public:
      * @param ec Set to indicate what error occurred, if any.
      */
     void listen(uint16_t port) {
-        listen(lib::asio::ip::tcp::v6(), port);
+        listen(lib::asio::ip::tcp::v4(), port);
     }
 
     /// Set up endpoint for listening on a host and service (exception free)
