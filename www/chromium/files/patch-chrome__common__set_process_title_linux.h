--- chrome/common/set_process_title_linux.h.orig	2011-03-20 22:02:04.219736445 +0200
+++ chrome/common/set_process_title_linux.h	2011-03-20 22:02:04.404739287 +0200
@@ -6,6 +6,9 @@
 #define CHROME_COMMON_SET_PROCESS_TITLE_LINUX_H_
 #pragma once
 
+#include "build/build_config.h"
+
+#if !defined(OS_FREEBSD)
 // Set the process title that will show in "ps" and similar tools. Takes
 // printf-style format string and arguments. After calling setproctitle()
 // the original main() argv[] array should not be used. By default, the
@@ -15,6 +18,7 @@
 // This signature and naming is to be compatible with most other Unix
 // implementations of setproctitle().
 void setproctitle(const char* fmt, ...);
+#endif
 
 // Initialize state needed for setproctitle() on Linux. Pass the argv pointer
 // from main() to setproctitle_init() before calling setproctitle().
