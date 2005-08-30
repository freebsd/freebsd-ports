--- src/pcheckd.c.orig	Sat Nov 22 22:27:22 2003
+++ src/pcheckd.c	Mon Jul 11 16:20:48 2005
@@ -511,7 +511,6 @@
 	case SIGQUIT: /* fallthrough */
 	case SIGINT:  /* fallthrough */
 	case SIGTERM: /* fallthrough */
-	case SIGPWR:  /* fallthrough */
 	  /* XLOG-DOC:INF:0078:shutdown
 	   * pcheckd received a QUIT, INT, TER, or PWR signal and is
 	   * shutting down. */
