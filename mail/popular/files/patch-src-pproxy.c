--- src/pproxy.c.orig	Mon Nov 24 20:23:30 2003
+++ src/pproxy.c	Mon Jul 11 16:21:13 2005
@@ -580,9 +580,6 @@
 	case SIGTERM:
 	  pproxy_shutdown(SHUTDOWN_CHILDREN | SHUTDOWN_SERVER);
 	  break;
-	case SIGPWR:
-	  pproxy_shutdown(SHUTDOWN_DELAYED);
-	  break;
 	case SIGHUP:
 	  logfd = xlog_reopen(conf.logfile, PPROXY_LOG_MODE);
 	  break;
