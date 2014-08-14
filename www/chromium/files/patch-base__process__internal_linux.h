--- ./base/process/internal_linux.h.orig	2014-08-12 21:01:27.000000000 +0200
+++ ./base/process/internal_linux.h	2014-08-13 09:56:56.000000000 +0200
@@ -12,6 +12,8 @@
 
 #include "base/files/file_path.h"
 
+#include <unistd.h> /* pid_t */
+
 namespace base {
 
 class Time;
