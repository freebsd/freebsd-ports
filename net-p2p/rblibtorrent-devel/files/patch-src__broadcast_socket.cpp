--- src/broadcast_socket.cpp.orig	2008-10-22 10:15:07.000000000 +0900
+++ src/broadcast_socket.cpp	2009-04-19 05:27:08.000000000 +0900
@@ -32,7 +32,7 @@
 
 #include <boost/version.hpp>
 
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/ip/host_name.hpp>
 #include <asio/ip/multicast.hpp>
 #else
