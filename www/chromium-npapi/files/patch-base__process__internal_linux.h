--- ./base/process/internal_linux.h.orig	2014-04-30 22:41:43.000000000 +0200
+++ ./base/process/internal_linux.h	2014-05-04 14:38:46.000000000 +0200
@@ -12,6 +12,8 @@
 
 #include "base/files/file_path.h"
 
+#include <unistd.h> /* pid_t */
+
 namespace base {
 
 class Time;
