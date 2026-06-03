--- src/ucs/sys/sys.h.orig	2026-02-05 12:41:56 UTC
+++ src/ucs/sys/sys.h
@@ -50,6 +50,8 @@
 #include <net/if.h>
 #include <netdb.h>
 #include <dirent.h>
+#include <limits.h>
+#include <unistd.h>
 
 
 #include <sys/types.h>
@@ -61,6 +63,14 @@ typedef cpuset_t ucs_sys_cpuset_t;
 typedef cpuset_t ucs_sys_cpuset_t;
 #else
 #error "Port me"
+#endif
+
+#ifndef UCS_HOST_NAME_MAX
+#  ifdef _POSIX_HOST_NAME_MAX
+#    define UCS_HOST_NAME_MAX _POSIX_HOST_NAME_MAX
+#  else
+#    define UCS_HOST_NAME_MAX 256
+#  endif
 #endif
 
 #define UCS_SYS_FS_SYSTEM_PATH "/sys/devices/system"
