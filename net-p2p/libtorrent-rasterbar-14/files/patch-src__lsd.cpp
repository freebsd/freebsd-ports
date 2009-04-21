--- src/lsd.cpp.orig	2009-02-12 03:16:27.000000000 +0900
+++ src/lsd.cpp	2009-04-19 05:30:17.000000000 +0900
@@ -41,7 +41,7 @@
 
 #include <boost/bind.hpp>
 #include <boost/ref.hpp>
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/ip/host_name.hpp>
 #include <asio/ip/multicast.hpp>
 #else
