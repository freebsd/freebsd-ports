Index: ksim/monitors/cpu/ksimcpu.cpp
===================================================================
RCS file: /home/kde/kdeutils/ksim/monitors/cpu/ksimcpu.cpp,v
retrieving revision 1.21
diff -u -5 -p -d -r1.21 ksimcpu.cpp
--- ksim/monitors/cpu/ksimcpu.cpp	13 May 2002 14:47:51 -0000	1.21
+++ ksim/monitors/cpu/ksimcpu.cpp	3 Mar 2003 07:38:33 -0000
@@ -40,12 +40,20 @@
 #include <chart.h>
 #include <progress.h>
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
 #ifdef Q_OS_NETBSD
 #include <sys/sched.h>
