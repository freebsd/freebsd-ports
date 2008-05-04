--- rmail/rmail.c.orig	2001-09-18 23:45:29.000000000 +0200
+++ rmail/rmail.c	2008-05-04 11:55:42.000000000 +0200
@@ -276,7 +276,11 @@
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
