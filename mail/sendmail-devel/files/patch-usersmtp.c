--- sendmail/usersmtp.c.orig	2026-03-09 16:19:10 UTC
+++ sendmail/usersmtp.c
@@ -1894,6 +1894,9 @@ attemptauth(MAILER *m, MCI *mci, ENVELOPE *e, SASL_AI_
 
 		if (saslresult != SASL_OK && saslresult != SASL_CONTINUE)
 		{
+			int fd = sm_io_getinfo(mci->mci_in, SM_IO_WHAT_FD, NULL);
+			BLOCKLIST_NOTIFY(BLOCKLIST_AUTH_FAIL, fd, "AUTH FAIL");
+
 			if (tTd(95, 5))
 				sm_dprintf("AUTH FAIL=%s (%d)\n",
 					sasl_errstring(saslresult, NULL, NULL),
@@ -2036,9 +2039,11 @@ smtpauth(MAILER *m, MCI *mci, ENVELOPE *e)
 	do
 	{
 		result = attemptauth(m, mci, e, &(mci->mci_sai));
-		if (result == EX_OK)
+		if (result == EX_OK) {
+			int fd = sm_io_getinfo(mci->mci_in, SM_IO_WHAT_FD, NULL);
+			BLOCKLIST_NOTIFY(BLOCKLIST_AUTH_OK, fd, "AUTH OK");
 			mci->mci_sasl_auth = true;
-		else if (result == EX_TEMPFAIL || result == EX_NOPERM)
+		} else if (result == EX_TEMPFAIL || result == EX_NOPERM)
 		{
 			mci->mci_saslcap = removemech((mci->mci_sai)[SASL_MECH],
 						      mci->mci_saslcap,
