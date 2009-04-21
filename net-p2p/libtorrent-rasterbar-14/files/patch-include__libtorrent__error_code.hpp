--- include/libtorrent/error_code.hpp.orig	2008-10-05 10:41:54.000000000 +0900
+++ include/libtorrent/error_code.hpp	2009-04-19 05:15:39.000000000 +0900
@@ -35,7 +35,7 @@
 
 #include <boost/version.hpp>
 
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/error_code.hpp>
 #else
 #include <boost/system/error_code.hpp>
@@ -53,7 +53,7 @@
 		};
 	}
 
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 	typedef asio::error_code error_code;
 	inline asio::error::error_category get_posix_category() { return asio::error::system_category; }
 	inline asio::error::error_category get_system_category() { return asio::error::system_category; }
