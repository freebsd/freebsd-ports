--- include/libtorrent/time.hpp.orig	2008-11-30 04:31:36.000000000 +0900
+++ include/libtorrent/time.hpp	2009-04-19 23:13:40.000000000 +0900
@@ -87,7 +87,7 @@
 
 #else
 
-#if BOOST_VERSION < 103500
+#if 1 // BOOST_VERSION < 103500
 #include <asio/time_traits.hpp>
 #else
 #include <boost/asio/time_traits.hpp>
@@ -159,7 +159,7 @@
 }
 
 // asio time_traits
-#if BOOST_VERSION >= 103500
+#if 0 // BOOST_VERSION >= 103500
 namespace boost { 
 #endif
 namespace asio
@@ -182,7 +182,7 @@
 		{ return boost::posix_time::microseconds(libtorrent::total_microseconds(d)); }
 	};
 }
-#if BOOST_VERSION >= 103500
+#if 0 // BOOST_VERSION >= 103500
 }
 #endif
 
