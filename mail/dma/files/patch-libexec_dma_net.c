--- libexec/dma/net.c.orig	2008-09-30 19:47:21.000000000 +0200
+++ libexec/dma/net.c	2009-01-17 19:02:43.000000000 +0100
@@ -342,14 +342,10 @@
 				it->queueid);
 		else
 			goto out;
-	}
-
-	/*
-	 * If the user doesn't want STARTTLS, but SSL encryption, we
-	 * have to enable SSL first, then send EHLO
-	 */
-	if (((config->features & STARTTLS) == 0) &&
-	    ((config->features & SECURETRANS) != 0)) {
+		/*
+		 * The client SHOULD send an EHLO command as the
+		 * first command after a successful TLS negotiation.
+		 */
 		send_remote_command(fd, "EHLO %s", hostname());
 		if (read_remote(fd, 0, NULL) != 2) {
 			syslog(LOG_ERR, "%s: remote delivery deferred: "
