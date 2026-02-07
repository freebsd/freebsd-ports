--- scam-back.c.orig	2010-02-21 07:20:47.000000000 +0000
+++ scam-back.c	2010-05-26 17:39:32.000000000 +0000
@@ -437,7 +437,7 @@
 
 #ifndef LINUX
 #ifdef ALLDOMAINS
-	backsslen = backss.ss_len
+	backsslen = backss.ss_len;
 #else
 	backsslen  = priv->backss.ss_len;
 #ifdef FALLBACKEND
@@ -1174,7 +1174,7 @@
 	{
 		syslog (LOG_ERR, "cannot open pidfile");
 	} else {
-		snprintf (buf, sizeof (buf), "%ld", (long) pid);
+		snprintf (buf, sizeof (buf), "%ld\n", (long) pid);
 		if (write (fd, buf, strlen (buf)) != strlen (buf)) {
 			syslog (LOG_ERR, "cannot write to pidfile");
 		}
