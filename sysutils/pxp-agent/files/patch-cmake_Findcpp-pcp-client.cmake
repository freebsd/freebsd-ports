--- cmake/Findcpp-pcp-client.cmake.orig	2018-09-28 17:04:38 UTC
+++ cmake/Findcpp-pcp-client.cmake
@@ -2,5 +2,5 @@ include(FindDependency)
 find_dependency(cpp-pcp-client
     DISPLAY "cpp-pcp-client"
     HEADERS "cpp-pcp-client/connector/connection.hpp"
-    LIBRARIES "libcpp-pcp-client.so" "libcpp-pcp-client.dylib" "cpp-pcp-client"
+    LIBRARIES "liblibcpp-pcp-client.so" "libcpp-pcp-client.dylib" "cpp-pcp-client"
     REQUIRED)
