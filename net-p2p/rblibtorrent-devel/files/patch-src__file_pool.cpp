--- src/file_pool.cpp.orig	2009-02-08 17:13:04.000000000 +0900
+++ src/file_pool.cpp	2009-04-19 05:29:34.000000000 +0900
@@ -62,7 +62,7 @@
 			{
 				// this means that another instance of the storage
 				// is using the exact same file.
-#if BOOST_VERSION >= 103500
+#if 0 // BOOST_VERSION >= 103500
 				ec = error_code(errors::file_collision, libtorrent_category);
 #endif
 				return boost::shared_ptr<file>();
