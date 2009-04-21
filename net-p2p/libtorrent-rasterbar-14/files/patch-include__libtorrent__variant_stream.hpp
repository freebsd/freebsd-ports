--- include/libtorrent/variant_stream.hpp.orig	2008-10-05 10:41:54.000000000 +0900
+++ include/libtorrent/variant_stream.hpp	2009-04-19 05:21:46.000000000 +0900
@@ -21,7 +21,7 @@
 # include <boost/type_traits/add_pointer.hpp>
 # include <boost/noncopyable.hpp>
 
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/io_service.hpp>
 #else
 #include <boost/asio/io_service.hpp>
