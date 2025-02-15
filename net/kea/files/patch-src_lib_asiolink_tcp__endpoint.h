--- src/lib/asiolink/tcp_endpoint.h.orig	2024-07-25 08:50:58 UTC
+++ src/lib/asiolink/tcp_endpoint.h
@@ -42,7 +42,7 @@ class TCPEndpoint : public IOEndpoint { (public)
     /// \param port The TCP port number of the endpoint.
     TCPEndpoint(const IOAddress& address, const unsigned short port) :
         asio_endpoint_placeholder_(
-            new boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(address.toText()),
+            new boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address(address.toText()),
                               port)),
         asio_endpoint_(*asio_endpoint_placeholder_)
     {}
