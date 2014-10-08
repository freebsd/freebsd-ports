--- base/process/process_iterator_freebsd.cc.orig	2014-10-02 17:18:52 UTC
+++ base/process/process_iterator_freebsd.cc
@@ -8,6 +8,10 @@
 #include <sys/sysctl.h>
 #include <unistd.h>
 
+/* getuid() */
+#include <unistd.h>
+#include <sys/types.h>
+
 #include "base/logging.h"
 #include "base/strings/string_util.h"
 
