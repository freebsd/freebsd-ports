--- src/imap4.c.orig	Mon Feb  4 17:37:40 2008
+++ src/imap4.c	Tue Feb  5 19:20:34 2008
@@ -120,7 +120,7 @@
 	} else {
 		if (dbmail_imap_session_printf(session,
 			     "* OK dbmail imap (protocol version 4r1) server %s "
-			     "ready to run\r\n", VERSION) < 0) {
+			     "ready to run\r\n", DBMAIL_VERSION) < 0) {
 			dbmail_imap_session_delete(session);
 			return EOF;
 		}
