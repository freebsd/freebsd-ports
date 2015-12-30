--- deps/v8/src/log-utils.h.orig	2015-12-09 04:12:52 UTC
+++ deps/v8/src/log-utils.h
@@ -5,6 +5,9 @@
 #ifndef V8_LOG_UTILS_H_
 #define V8_LOG_UTILS_H_
 
+#include <cstdio>
+#include <cstdarg>
+
 #include "src/allocation.h"
 #include "src/base/platform/mutex.h"
 #include "src/flags.h"
