--- agent/mibgroup/ucd-snmp/vmstat_freebsd2.c.orig	Thu May 23 17:39:41 2002
+++ agent/mibgroup/ucd-snmp/vmstat_freebsd2.c	Thu Feb 20 08:08:20 2003
@@ -10,7 +10,11 @@
 #include <sys/param.h>
 #include <sys/time.h>
 #include <sys/proc.h>
+#if defined(freebsd5) && __FreeBSD_version >= 500101
+#include <sys/resource.h>
+#else
 #include <sys/dkstat.h>
+#endif
 #ifdef freebsd5
 #include <sys/bio.h>
 #endif
