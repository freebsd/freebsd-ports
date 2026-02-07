--- src/3rdparty/gn/tools/gn/exec_process.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/gn/tools/gn/exec_process.cc
@@ -22,6 +22,9 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <sys/wait.h>
+#if defined(OS_BSD)
+#include <sys/signal.h>
+#endif
 #include <unistd.h>
 
 #include "base/posix/eintr_wrapper.h"
