--- include/libtorrent/proxy_base.hpp.orig	2008-10-05 10:41:54.000000000 +0900
+++ include/libtorrent/proxy_base.hpp	2009-04-19 05:17:07.000000000 +0900
@@ -38,7 +38,7 @@
 #include <boost/bind.hpp>
 #include <boost/lexical_cast.hpp>
 #include <boost/function.hpp>
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/read.hpp>
 #include <asio/write.hpp>
 #else
