--- src/response.c.orig	Mon Dec 18 01:21:53 2000
+++ src/response.c	Mon Mar  5 18:48:15 2001
@@ -480,9 +480,11 @@
 sendEntityDone(thd)
 	Thread *	thd;
 {
+#if	0
   /* send end line (CRLF only) */
   thd->sendcnt = snprintf(thd->sendbuf, sizeof(thd->sendbuf), "%s", CRLF);
   writeData(thd);
+#endif
   thd->status = TERMINATED;
 #if	defined(BUGGY_KEEP_ALIVE) && defined(DEBUG)
   if (thd->keepAlive.state == KA_CONTINUE) {
