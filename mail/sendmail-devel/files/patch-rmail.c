--- rmail/rmail.c.orig	2026-03-09 16:19:10 UTC
+++ rmail/rmail.c
@@ -273,7 +273,11 @@ main(int argc, char *argv[])
 	args[i++] = _PATH_SENDMAIL;	/* Build sendmail's argument list. */
 	args[i++] = "-G";		/* relay submission */
 	args[i++] = "-oee";		/* No errors, just status. */
+#ifdef QUEUE_ONLY
 	args[i++] = "-odq";		/* Queue it, don't try to deliver. */
+#else
+	args[i++] = "-odi";		/* Deliver in foreground. */
+#endif
 	args[i++] = "-oi";		/* Ignore '.' on a line by itself. */
 
 	/* set from system and protocol used */
