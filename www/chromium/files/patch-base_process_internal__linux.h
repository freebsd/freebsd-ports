--- base/process/internal_linux.h.orig	2017-04-19 19:06:28 UTC
+++ base/process/internal_linux.h
@@ -14,6 +14,8 @@
 
 #include "base/files/file_path.h"
 
+#include <unistd.h> /* pid_t */
+
 namespace base {
 
 class Time;
