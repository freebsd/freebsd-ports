--- ./base/process/internal_linux.h.orig	2013-09-03 09:09:03.000000000 +0200
+++ ./base/process/internal_linux.h	2013-09-07 21:29:08.000000000 +0200
@@ -10,6 +10,8 @@
 
 #include "base/files/file_path.h"
 
+#include <unistd.h> /* pid_t */
+
 namespace base {
 namespace internal {
 
