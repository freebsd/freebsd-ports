--- src/upnp.cpp.orig	2009-02-18 17:42:16.000000000 +0900
+++ src/upnp.cpp	2009-04-19 05:33:50.000000000 +0900
@@ -43,7 +43,7 @@
 
 #include <boost/bind.hpp>
 #include <boost/ref.hpp>
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/ip/host_name.hpp>
 #include <asio/ip/multicast.hpp>
 #else
