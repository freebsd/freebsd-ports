--- src/pproxy.c.orig	2003-11-24 19:23:30 UTC
+++ src/pproxy.c
@@ -580,9 +580,6 @@ main(int argc, char *argv[])
 	case SIGTERM:
 	  pproxy_shutdown(SHUTDOWN_CHILDREN | SHUTDOWN_SERVER);
 	  break;
-	case SIGPWR:
-	  pproxy_shutdown(SHUTDOWN_DELAYED);
-	  break;
 	case SIGHUP:
 	  logfd = xlog_reopen(conf.logfile, PPROXY_LOG_MODE);
 	  break;
