--- src/3rdparty/chromium/base/process/internal_linux.h.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/process/internal_linux.h
@@ -14,6 +14,8 @@
 
 #include "base/files/file_path.h"
 
+#include <unistd.h> /* pid_t */
+
 namespace base {
 
 class Time;
