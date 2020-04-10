--- src/Logging.cpp.orig	2020-04-10 01:02:36 UTC
+++ src/Logging.cpp
@@ -27,6 +27,10 @@
 
 #include "rtcdcpp/Logging.hpp"
 
+#ifndef SPDLOG_DISABLED
+#include <spdlog/sinks/stdout_color_sinks.h>
+#endif
+
 namespace rtcdcpp {
 
 #ifndef SPDLOG_DISABLED
