--- OpenSim/Common/Logger.h.orig	2026-06-18 22:26:24 UTC
+++ OpenSim/Common/Logger.h
@@ -25,8 +25,9 @@
 #include "osimCommonDLL.h"              // for OSIMCOMMON_API
 #include <memory>                       // for shared_ptr
 #include <spdlog/common.h>              // for spdlog::format_string_t
-#include <spdlog/fmt/bundled/base.h>    // for formatter
-#include <spdlog/fmt/bundled/ostream.h> // for ostream_formatter
+// On FreeBSD fmt is not bundled with spdlog
+#include <fmt/base.h>    // for formatter
+#include <fmt/ostream.h> // for ostream_formatter
 #include <spdlog/logger.h>              // for logger
 #include <string>                       // for basic_string, string
 #include <string_view>                  // for std::string_view
