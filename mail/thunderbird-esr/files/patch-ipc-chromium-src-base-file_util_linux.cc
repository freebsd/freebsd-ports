--- mozilla/ipc/chromium/src/base/file_util_linux.cc~
+++ mozilla/ipc/chromium/src/base/file_util_linux.cc
@@ -5,6 +5,7 @@
 #include "base/file_util.h"
 
 #include <fcntl.h>
+#include <unistd.h>
 
