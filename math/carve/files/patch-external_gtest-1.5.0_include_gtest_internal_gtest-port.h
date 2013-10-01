--- external/gtest-1.5.0/include/gtest/internal/gtest-port.h.orig	2011-08-26 20:16:23.000000000 +0000
+++ external/gtest-1.5.0/include/gtest/internal/gtest-port.h
@@ -176,6 +176,7 @@
 #ifndef _WIN32_WCE
 #include <sys/stat.h>
 #endif  // !_WIN32_WCE
+#include <unistd.h>
 
 #include <iostream>  // NOLINT
 #include <sstream>  // NOLINT
