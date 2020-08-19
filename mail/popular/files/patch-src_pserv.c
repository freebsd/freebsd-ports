--- src/pserv.c.orig	2002-09-15 12:27:16 UTC
+++ src/pserv.c
@@ -484,9 +484,6 @@ main(int argc, char *argv[])
 	case SIGTERM:
 	  pserv_shutdown(SHUTDOWN_CHILDREN | SHUTDOWN_SERVER);
 	  break;
-	case SIGPWR:
-	  pserv_shutdown(SHUTDOWN_DELAYED);
-	  break;
 	case SIGHUP:
 	  xlog_reopen(conf.logfile, PSERV_LOG_MODE);
 	  break;
