--- ./base/process/internal_linux.h.orig	2014-08-20 21:02:41.000000000 +0200
+++ ./base/process/internal_linux.h	2014-08-22 15:06:24.000000000 +0200
@@ -12,6 +12,8 @@
 
 #include "base/files/file_path.h"
 
+#include <unistd.h> /* pid_t */
+
 namespace base {
 
 class Time;
