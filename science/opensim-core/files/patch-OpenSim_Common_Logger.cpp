--- OpenSim/Common/Logger.cpp.orig	2026-06-18 22:26:24 UTC
+++ OpenSim/Common/Logger.cpp
@@ -26,7 +26,8 @@
 #include "IO.h"                              // for IO
 #include "LogSink.h"                         // for LogSink
 #include <algorithm>                         // for remove
-#include <spdlog/fmt/bundled/format.h>       // for format
+// On FreeBSD fmt is not bundled with spdlog
+#include <fmt/format.h>       // for format
 #include <spdlog/sinks/basic_file_sink.h>    // for basic_file_sink_mt, bas...
 #include <spdlog/sinks/sink.h>               // for sink
 #include <spdlog/sinks/stdout_color_sinks.h> // for stdout_color_mt
