- https://github.com/cp-profiler/cpp-integration/issues/1

--- submodules/cp-profiler-integration/connector.hpp.orig	2021-05-03 23:30:50 UTC
+++ submodules/cp-profiler-integration/connector.hpp
@@ -7,6 +7,7 @@
 #include <sstream>
 #include <vector>
 #include <cstring>
+#include <sys/socket.h>
 
 #ifdef WIN32
 
