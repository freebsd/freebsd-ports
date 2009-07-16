--- src/imap4.c.orig	Sun Jun 28 17:48:24 2009
+++ src/imap4.c	Mon Jul 13 21:25:51 2009
@@ -204,7 +204,7 @@
 	if (strlen(banner) > 0)
 		imap_session_printf(session, "* OK %s\r\n", banner);
 	else
-		imap_session_printf(session, "* OK imap 4r1 server (dbmail %s)\r\n", VERSION);
+		imap_session_printf(session, "* OK imap 4r1 server (dbmail %s)\r\n", DBMAIL_VERSION);
 	dbmail_imap_session_set_state(session,CLIENTSTATE_NON_AUTHENTICATED);
 }
 
