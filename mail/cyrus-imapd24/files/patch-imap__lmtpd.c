--- imap/lmtpd.c.orig	2017-05-15 05:43:30 UTC
+++ imap/lmtpd.c
@@ -712,9 +712,10 @@ int deliver(message_data_t *msgdata, cha
 
     /* loop through each recipient, attempting delivery for each */
     for (n = 0; n < nrcpts; n++) {
-	char namebuf[MAX_MAILBOX_BUFFER] = "", *server;
+	char namebuf[MAX_MAILBOX_BUFFER] = "";
 	char userbuf[MAX_MAILBOX_BUFFER];
 	const char *rcpt, *user, *domain, *mailbox;
+	char *server = NULL;
 	int r = 0;
 
 	rcpt = msg_getrcptall(msgdata, n);
@@ -954,7 +955,7 @@ static int verify_user(const char *user,
     }
 
     if (!r) {
-	char *server, *acl;
+	char *server = NULL, *acl = NULL;
 	long aclcheck = !user ? ACL_POST : 0;
 	/*
 	 * check to see if mailbox exists and we can append to it:
@@ -1061,8 +1062,9 @@ FILE *spoolfile(message_data_t *msgdata)
        (don't bother if we're only a proxy) */
     n = isproxy ? 0 : msg_getnumrcpt(msgdata);
     for (i = 0; !f && (i < n); i++) {
-	char namebuf[MAX_MAILBOX_BUFFER] = "", *server;
+	char namebuf[MAX_MAILBOX_BUFFER] = "";
 	const char *user, *domain, *mailbox;
+	char *server = NULL;
 	int r;
 
 	/* build the mailboxname from the recipient address */
