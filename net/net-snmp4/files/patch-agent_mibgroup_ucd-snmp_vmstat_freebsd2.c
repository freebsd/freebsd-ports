--- agent/mibgroup/ucd-snmp/vmstat_freebsd2.c.orig	Fri Mar 28 13:15:48 2003
+++ agent/mibgroup/ucd-snmp/vmstat_freebsd2.c	Fri Mar 28 13:16:31 2003
@@ -8,11 +8,14 @@
 #include <sys/param.h>
 #include <sys/time.h>
 #include <sys/proc.h>
+#if __FreeBSD_version < 500101
 #include <sys/dkstat.h>
+#endif
 #ifdef freebsd5
 #include <sys/bio.h>
 #endif
 #include <sys/buf.h>
+#include <sys/resource.h>
 #include <sys/uio.h>
 #include <sys/namei.h>
 #include <sys/malloc.h>
