--- base/process/launch_posix.cc.orig	2016-10-06 04:02:08.000000000 +0300
+++ base/process/launch_posix.cc	2016-10-16 15:45:00.730008000 +0300
@@ -62,6 +62,7 @@
 #include <sys/event.h>
 #else
 extern char** environ;
+#pragma weak environ
 #endif
 
 namespace base {
