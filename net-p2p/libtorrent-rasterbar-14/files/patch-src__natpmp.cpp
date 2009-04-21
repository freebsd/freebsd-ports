--- src/natpmp.cpp.orig	2009-02-08 17:13:04.000000000 +0900
+++ src/natpmp.cpp	2009-04-19 05:30:54.000000000 +0900
@@ -35,7 +35,7 @@
 #include <boost/version.hpp>
 #include <boost/bind.hpp>
 
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/ip/host_name.hpp>
 #else
 #include <boost/asio/ip/host_name.hpp>
