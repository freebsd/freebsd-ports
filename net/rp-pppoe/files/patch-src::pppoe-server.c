--- src/pppoe-server.c.orig	Mon Feb  5 14:34:27 2001
+++ src/pppoe-server.c	Thu Mar 22 17:56:25 2001
@@ -47,6 +47,10 @@
 #include <sys/wait.h>
 #endif
 
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
 #include <signal.h>
 
 /* Hack for daemonizing */
@@ -1032,7 +1036,11 @@
     char buffer[SMALLBUF];
 
     argv[0] = "pppd";
+#if (defined(BSD) && (BSD >= 199103))
+    argv[1] = "tty";
+#else /* Not BSD, e.g., Linux || Solaris */
     argv[1] = "pty";
+#endif
 
     snprintf(buffer, SMALLBUF, "%s -I %s -e %d:%02x:%02x:%02x:%02x:%02x:%02x%s",
 	     PPPOE_PATH, IfName,
