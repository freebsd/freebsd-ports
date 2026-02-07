--- rmail/rmail.c.orig	2014-03-05 00:59:45 UTC
+++ rmail/rmail.c
@@ -276,7 +276,11 @@ main(argc, argv)
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
