--- base/process/internal_linux.h.orig	2014-10-10 08:54:09 UTC
+++ base/process/internal_linux.h
@@ -12,6 +12,8 @@
 
 #include "base/files/file_path.h"
 
+#include <unistd.h> /* pid_t */
+
 namespace base {
 
 class Time;
