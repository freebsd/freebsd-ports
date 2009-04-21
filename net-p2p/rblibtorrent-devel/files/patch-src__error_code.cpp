--- src/error_code.cpp.orig	2008-10-05 10:41:56.000000000 +0900
+++ src/error_code.cpp	2009-04-19 05:35:55.000000000 +0900
@@ -32,7 +32,7 @@
 
 #include <boost/version.hpp>
 
-#if BOOST_VERSION >= 103500
+#if 0 // BOOST_VERSION >= 103500
 
 #include "libtorrent/error_code.hpp"
 
