--- src/pcheckd.c.orig	2003-11-22 21:27:22 UTC
+++ src/pcheckd.c
@@ -511,7 +511,6 @@ main(int argc, char *argv[])
 	case SIGQUIT: /* fallthrough */
 	case SIGINT:  /* fallthrough */
 	case SIGTERM: /* fallthrough */
-	case SIGPWR:  /* fallthrough */
 	  /* XLOG-DOC:INF:0078:shutdown
 	   * pcheckd received a QUIT, INT, TER, or PWR signal and is
 	   * shutting down. */
