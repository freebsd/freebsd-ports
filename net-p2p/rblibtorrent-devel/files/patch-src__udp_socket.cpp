--- src/udp_socket.cpp.orig	2009-02-08 17:13:04.000000000 +0900
+++ src/udp_socket.cpp	2009-04-19 05:33:12.000000000 +0900
@@ -36,7 +36,7 @@
 #include <stdlib.h>
 #include <boost/bind.hpp>
 #include <boost/array.hpp>
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/read.hpp>
 #else
 #include <boost/asio/read.hpp>
