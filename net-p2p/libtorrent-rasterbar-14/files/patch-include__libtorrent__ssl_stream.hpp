--- include/libtorrent/ssl_stream.hpp.orig	2008-10-21 17:07:26.000000000 +0900
+++ include/libtorrent/ssl_stream.hpp	2009-04-19 05:19:42.000000000 +0900
@@ -34,7 +34,7 @@
 #define TORRENT_SSL_STREAM_HPP_INCLUDED
 
 #include "libtorrent/socket.hpp"
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/ssl.hpp>
 #else
 #include <boost/asio/ssl.hpp>
