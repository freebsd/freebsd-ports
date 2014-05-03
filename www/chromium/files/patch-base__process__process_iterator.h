--- ./base/process/process_iterator.h.orig	2014-04-24 22:36:10.000000000 +0200
+++ ./base/process/process_iterator.h	2014-04-24 23:23:41.000000000 +0200
@@ -21,6 +21,11 @@
 #include <windows.h>
 #include <tlhelp32.h>
 #elif defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_BSD)
+#include <kvm.h>
+#include <sys/param.h>
+#include <sys/user.h>
+#endif
 #include <sys/sysctl.h>
 #elif defined(OS_POSIX)
 #include <dirent.h>
