--- ./base/process/process_iterator_freebsd.cc.orig	2013-09-03 09:09:03.000000000 +0200
+++ ./base/process/process_iterator_freebsd.cc	2013-09-07 21:31:37.000000000 +0200
@@ -6,6 +6,10 @@
 
 #include <sys/sysctl.h>
 
+/* getuid() */
+#include <unistd.h>
+#include <sys/types.h>
+
 #include "base/logging.h"
 #include "base/strings/string_util.h"
 
