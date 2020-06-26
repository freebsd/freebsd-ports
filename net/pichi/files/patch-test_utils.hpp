--- test/utils.hpp.orig	1970-01-01 00:00:00 UTC
+++ test/utils.hpp
@@ -1,6 +1,8 @@
 #ifndef PICHI_TEST_UTILS_HPP
 #define PICHI_TEST_UTILS_HPP
 
+#include <pichi/config.hpp>
+// Include config.hpp first
 #include <boost/asio/error.hpp>
 #include <boost/beast/http/error.hpp>
 #include <pichi/api/vos.hpp>
