--- src/3rdparty/chromium/base/process/process_posix.cc.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/base/process/process_posix.cc
@@ -8,6 +8,7 @@
 #include <stdint.h>
 #include <sys/resource.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 #include "base/files/scoped_file.h"
 #include "base/logging.h"
