Index: ksimdisk.cpp
===================================================================
RCS file: /home/kde/kdeutils/ksim/monitors/disk/ksimdisk.cpp,v
retrieving revision 1.13
diff -u -5 -p -d -r1.13 ksimdisk.cpp
--- ksimdisk.cpp	2 Nov 2002 14:34:08 -0000	1.13
+++ ksim/monitors/disk/ksimdisk.cpp	3 Mar 2003 08:48:34 -0000
@@ -39,11 +39,16 @@
 #include <chart.h>
 #include <progress.h>
 #include <themetypes.h>
 
 #ifdef Q_OS_FREEBSD
+#include <sys/param.h>
+#if __FreeBSD_version < 500101
 #include <sys/dkstat.h>
+#else
+#include <sys/resource.h>
+#endif
 #include <devstat.h>
 #include <stdlib.h>
 #endif
 
 #ifdef Q_OS_LINUX
