--- agent/mibgroup/ucd-snmp/diskio.c.orig	Mon May 20 03:38:58 2002
+++ agent/mibgroup/ucd-snmp/diskio.c	Thu Feb 20 07:53:08 2003
@@ -49,7 +49,12 @@
 #endif                          /* bsdi */
 
 #if defined (freebsd4) || defined(freebsd5)
+#include <sys/param.h>
+#if __FreeBSD_version >= 500101
+#include <sys/resource.h>
+#else
 #include <sys/dkstat.h>
+#endif
 #include <devstat.h>
 #endif                          /* freebsd */
 
