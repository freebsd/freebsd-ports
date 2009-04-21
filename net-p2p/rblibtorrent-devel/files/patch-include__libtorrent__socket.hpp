--- include/libtorrent/socket.hpp.orig	2009-02-08 17:13:07.000000000 +0900
+++ include/libtorrent/socket.hpp	2009-04-19 05:18:58.000000000 +0900
@@ -47,7 +47,7 @@
 
 #include <boost/version.hpp>
 
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/ip/tcp.hpp>
 #include <asio/ip/udp.hpp>
 #include <asio/io_service.hpp>
@@ -82,7 +82,7 @@
 namespace libtorrent
 {
 
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 	using asio::ip::tcp;
 	using asio::ip::udp;
 	using asio::async_write;
