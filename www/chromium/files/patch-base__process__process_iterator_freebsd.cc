--- ./base/process/process_iterator_freebsd.cc.orig	2014-04-24 22:36:10.000000000 +0200
+++ ./base/process/process_iterator_freebsd.cc	2014-04-24 23:23:41.000000000 +0200
@@ -6,6 +6,10 @@
 
 #include <sys/sysctl.h>
 
+/* getuid() */
+#include <unistd.h>
+#include <sys/types.h>
+
 #include "base/logging.h"
 #include "base/strings/string_util.h"
 
