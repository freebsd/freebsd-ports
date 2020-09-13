--- src/net/spawn.cpp.orig	1970-01-01 00:00:00 UTC
+++ src/net/spawn.cpp
@@ -1,3 +1,5 @@
+#include <pichi/config.hpp>
+// Include config.hpp first
 #include <boost/beast/http/error.hpp>
 #include <iostream>
 #include <pichi/exception.hpp>
@@ -28,4 +30,4 @@ void logException(std::exception_ptr eptr) noexcept
 
 void stubHandler(std::exception_ptr, asio::yield_context) noexcept {}
 
-} // namespace pichi::net
+}  // namespace pichi::net
