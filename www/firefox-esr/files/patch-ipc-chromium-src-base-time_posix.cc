--- ipc/chromium/src/base/time_posix.cc~
+++ ipc/chromium/src/base/time_posix.cc
@@ -8,6 +9,7 @@
 #include <mach/mach_time.h>
 #endif
 #include <sys/time.h>
+#include <unistd.h>
 #ifdef ANDROID
 #include <time64.h>
 #else
