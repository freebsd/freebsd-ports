--- src/pserv.c.orig	Sun Sep 15 14:27:16 2002
+++ src/pserv.c	Mon Jul 11 16:23:03 2005
@@ -484,9 +484,6 @@
 	case SIGTERM:
 	  pserv_shutdown(SHUTDOWN_CHILDREN | SHUTDOWN_SERVER);
 	  break;
-	case SIGPWR:
-	  pserv_shutdown(SHUTDOWN_DELAYED);
-	  break;
 	case SIGHUP:
 	  xlog_reopen(conf.logfile, PSERV_LOG_MODE);
 	  break;
