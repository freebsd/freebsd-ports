--- ksim/monitors/cpu/ksimcpu.cpp.orig	Mon May 13 10:47:51 2002
+++ ksim/monitors/cpu/ksimcpu.cpp	Mon Mar 17 13:26:46 2003
@@ -42,8 +42,16 @@
 #include <themetypes.h>
 
 #ifdef Q_OS_BSD4
-#include <sys/dkstat.h>
 #include <sys/param.h>
+#ifdef Q_OS_FREEBSD
+#if __FreeBSD_version < 500101
+#include <sys/dkstat.h>
+#else
+#include <sys/resource.h>
+#endif
+#else
+#include <sys/dkstat.h>
+#endif
 #include <sys/sysctl.h>
 #include <string.h>
 #include <kvm.h>
@@ -246,8 +254,8 @@
   static int oidCpuTime[CTL_MAXNAME + 2];
   static size_t oidCpuTimeLen = sizeof(oidCpuTime);
   long cpuTime[CPUSTATES];
-  unsigned int cpuTimeLen = sizeof(cpuTime);
-  static char *name = "kern.cp_time";
+  size_t cpuTimeLen = sizeof(cpuTime);
+  static const char *name = "kern.cp_time";
   static int initialized = 0;
 
   if (!initialized) {
