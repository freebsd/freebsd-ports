--- error.c.orig	Mon Jun 24 02:27:37 2002
+++ error.c	Mon Jun 24 02:28:05 2002
@@ -215,7 +215,7 @@
 #if defined(HAVE_OPENLOG) && defined(HAVE_SYSLOG)
       if (daemon (cd != NULL, 0) < 0)
 	msg (M_ERR, "daemon() failed");
-      openlog ("openvpn", LOG_PID, 0);
+      openlog ("openvpn", LOG_PID, LOG_DAEMON);
 #else
       msg (M_WARN, "Warning: this operating system lacks daemon logging features, therefore when I become a daemon, I won't be able to log status or error messages");
       if (daemon (cd != NULL, 0) < 0)
