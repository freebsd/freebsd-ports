--- include/libtorrent/chained_buffer.hpp.orig	2008-10-05 10:41:54.000000000 +0900
+++ include/libtorrent/chained_buffer.hpp	2009-04-19 05:13:19.000000000 +0900
@@ -35,7 +35,7 @@
 
 #include <boost/function.hpp>
 #include <boost/version.hpp>
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/buffer.hpp>
 #else
 #include <boost/asio/buffer.hpp>
@@ -45,7 +45,7 @@
 
 namespace libtorrent
 {
-#if BOOST_VERSION >= 103500
+#if 0 // BOOST_VERSION >= 103500
 	namespace asio = boost::asio;
 #endif
 	struct chained_buffer
