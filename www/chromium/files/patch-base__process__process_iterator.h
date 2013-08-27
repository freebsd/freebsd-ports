--- base/process/process_iterator.h.orig	2013-08-16 22:08:02.000000000 +0300
+++ base/process/process_iterator.h	2013-08-16 22:08:08.000000000 +0300
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
