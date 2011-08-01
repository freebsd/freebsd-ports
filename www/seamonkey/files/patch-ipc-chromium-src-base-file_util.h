--- mozilla/ipc/chromium/src/base/file_util.h~
+++ mozilla/ipc/chromium/src/base/file_util.h
@@ -15,8 +15,9 @@
 #elif defined(ANDROID)
 #include <sys/stat.h>
 #elif defined(OS_POSIX) 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <fts.h>
-#include <sys/stat.h>
 #endif
 
 #include <stdio.h>
