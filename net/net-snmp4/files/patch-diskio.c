--- agent/mibgroup/ucd-snmp/diskio.c.orig	Mon Sep 17 06:49:41 2001
+++ agent/mibgroup/ucd-snmp/diskio.c	Wed Feb 13 22:22:45 2002
@@ -46,10 +46,10 @@
 #include <sys/diskstats.h>
 #endif /* bsdi */
 
-#if defined (freebsd4)
+#if __FreeBSD__ >= 4
 #include <sys/dkstat.h>
 #include <devstat.h>
-#endif /* freebsd */
+#endif /* __FreeBSD__ */
 
 
          /*********************
@@ -298,7 +298,7 @@
 }
 #endif /* bsdi */
 
-#if defined(freebsd4)
+#if __FreeBSD__ >= 4
 static int ndisk;
 static struct statinfo *stat;
 
@@ -377,5 +377,5 @@
   }
   return NULL;
 }
-#endif /* freebsd4 */
+#endif /* __FreeBSD__ >= 4 */
 
