--- base/process/process_posix.cc.orig	2015-05-20 21:26:57.068650000 -0400
+++ base/process/process_posix.cc	2015-05-20 21:25:28.077153000 -0400
@@ -17,6 +17,10 @@
 #include <sys/event.h>
 #endif
 
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
+
 namespace {
 
 #if !defined(OS_NACL_NONSFI)
