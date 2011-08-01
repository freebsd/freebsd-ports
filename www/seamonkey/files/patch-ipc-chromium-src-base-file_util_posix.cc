--- mozilla/ipc/chromium/src/base/file_util_posix.cc~
+++ mozilla/ipc/chromium/src/base/file_util_posix.cc
@@ -30,6 +30,8 @@
 #include "base/string_util.h"
 #include "base/time.h"
 
+#define stat64 stat
+
 namespace file_util {
 
 #if defined(GOOGLE_CHROME_BUILD)
