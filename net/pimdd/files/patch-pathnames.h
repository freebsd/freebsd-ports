--- pathnames.h.orig	1999-11-30 17:58:53 UTC
+++ pathnames.h
@@ -47,7 +47,9 @@
  */
 
 
+#ifndef _PATH_PIMD_CONF
 #define _PATH_PIMD_CONF		"/etc/pimd.conf"
+#endif
 
 #if (defined(BSD) && (BSD >= 199103))
 #define _PATH_PIMD_PID		"/var/run/pimdd.pid"
