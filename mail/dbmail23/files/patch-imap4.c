--- src/imap4.c.orig	Tue Jan  6 14:51:55 2009
+++ src/imap4.c	Sun Jan 25 18:35:09 2009
@@ -172,7 +172,7 @@
 	if (strlen(banner) > 0)
 		imap_session_printf(session, "* OK %s\r\n", banner);
 	else
-		imap_session_printf(session, "* OK imap 4r1 server (dbmail %s)\r\n", VERSION);
+		imap_session_printf(session, "* OK imap 4r1 server (dbmail %s)\r\n", DBMAIL_VERSION);
 	dbmail_imap_session_set_state(session,IMAPCS_NON_AUTHENTICATED);
 }
 
