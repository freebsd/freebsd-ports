Index: src/sysdeps/freebsd.c
diff -u src/sysdeps/freebsd.c.orig src/sysdeps/freebsd.c
--- src/sysdeps/freebsd.c.orig	Wed Jan 22 00:17:21 2003
+++ src/sysdeps/freebsd.c	Thu Feb 20 19:29:34 2003
@@ -81,7 +81,12 @@
 /* ===================================================================== */
 /* CPU monitor interface */
 
+#include <osreldate.h>
+#if __FreeBSD_version >= 500101
+#include <sys/resource.h>
+#else
 #include <sys/dkstat.h>
+#endif
 #include <kvm.h>
 
 
@@ -301,8 +306,6 @@
 /* ===================================================================== */
 /* Disk monitor interface */
 
-#include <osreldate.h>
-#include <sys/dkstat.h>
 #if __FreeBSD_version >= 300000
 #include <devstat.h>
 static struct statinfo	statinfo_cur;
