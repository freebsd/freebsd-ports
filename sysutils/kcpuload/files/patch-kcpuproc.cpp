--- kcpuload/kcpuproc.cpp.orig	Fri Dec 20 10:48:06 2002
+++ kcpuload/kcpuproc.cpp	Wed May  7 09:33:48 2003
@@ -18,8 +18,12 @@
 
 // BSD-specific includes.
 #ifdef Q_OS_BSD4
-#include <sys/dkstat.h>
 #include <sys/param.h>
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500101
+#include <sys/resource.h>
+#else
+#include <sys/dkstat.h>
+#endif
 #include <sys/sysctl.h>
 #include <string.h>
 #include <kvm.h>
@@ -119,7 +123,7 @@
     static int oidCpuTime[CTL_MAXNAME + 2];
     static size_t oidCpuTimeLen = sizeof(oidCpuTime);
     long cpuTime[CPUSTATES];
-    unsigned int cpuTimeLen = sizeof(cpuTime);
+    size_t cpuTimeLen = sizeof(cpuTime);
     static char *name = "kern.cp_time";
     static int initialized = 0;
 #endif
