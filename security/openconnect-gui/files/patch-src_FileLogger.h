--- src/FileLogger.h.orig	2021-02-18 01:03:58 UTC
+++ src/FileLogger.h
@@ -1,6 +1,7 @@
 #pragma once
 
 #include "spdlog/spdlog.h"
+#include "spdlog/sinks/rotating_file_sink.h"
 
 #include <QObject>
 #include <QStandardPaths>
