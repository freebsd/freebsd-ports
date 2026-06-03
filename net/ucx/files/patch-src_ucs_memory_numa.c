--- src/ucs/memory/numa.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucs/memory/numa.c
@@ -20,6 +20,20 @@
 #include <sched.h>
 #include <dirent.h>
 
+#ifndef __CPU_SETSIZE
+#  if defined(__FreeBSD__)
+#    include <sys/param.h>
+#    include <sys/cpuset.h>
+#  endif
+#  if defined(CPU_SETSIZE)
+#    define __CPU_SETSIZE CPU_SETSIZE
+#  elif defined(MAXCPU)
+#    define __CPU_SETSIZE MAXCPU
+#  else
+#    define __CPU_SETSIZE 1024
+#  endif
+#endif
+
 #define UCS_NUMA_MIN_DISTANCE       10
 #define UCS_NUMA_NODE_MAX           INT16_MAX
 #define UCS_NUMA_CORE_DIR_PATH      UCS_SYS_FS_CPUS_PATH "/cpu%d"
