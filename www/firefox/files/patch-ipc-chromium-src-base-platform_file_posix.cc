--- ipc/chromium/src/base/platform_file_posix.cc~
+++ ipc/chromium/src/base/platform_file_posix.cc
@@ -9,6 +9,7 @@
 #ifdef ANDROID
 #include <linux/stat.h>
 #endif
+#include <sys/stat.h>
 
 #include "base/logging.h"
 #include "base/string_util.h"
