--- src/enum_net.cpp.orig	2009-02-08 17:13:04.000000000 +0900
+++ src/enum_net.cpp	2009-04-19 05:28:22.000000000 +0900
@@ -35,7 +35,7 @@
 #include <vector>
 #include "libtorrent/enum_net.hpp"
 #include "libtorrent/broadcast_socket.hpp"
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/ip/host_name.hpp>
 #else
 #include <boost/asio/ip/host_name.hpp>
