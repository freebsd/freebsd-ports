--- src/common/slogger.h.orig	2017-12-20 09:59:37 UTC
+++ src/common/slogger.h
@@ -27,6 +27,9 @@
 #endif
 #include "common/small_vector.h"
 #include "spdlog/spdlog.h"
+#include "spdlog/sinks/syslog_sink.h"
+#include "spdlog/sinks/stdout_color_sinks.h"
+#include "spdlog/sinks/rotating_file_sink.h"
 
 typedef std::shared_ptr<spdlog::logger> LoggerPtr;
 
