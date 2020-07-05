--- sendmail/usersmtp.c.orig	2020-06-03 05:48:46 UTC
+++ sendmail/usersmtp.c
@@ -1842,6 +1842,9 @@ attemptauth(m, mci, e, sai)
 
 		if (saslresult != SASL_OK && saslresult != SASL_CONTINUE)
 		{
+			int fd = sm_io_getinfo(mci->mci_in, SM_IO_WHAT_FD, NULL);
+			BLACKLIST_NOTIFY(BLACKLIST_AUTH_FAIL, fd, "AUTH FAIL");
+
 			if (tTd(95, 5))
 				sm_dprintf("AUTH FAIL=%s (%d)\n",
 					sasl_errstring(saslresult, NULL, NULL),
@@ -1987,9 +1990,11 @@ smtpauth(m, mci, e)
 	do
 	{
 		result = attemptauth(m, mci, e, &(mci->mci_sai));
-		if (result == EX_OK)
+		if (result == EX_OK) {
+			int fd = sm_io_getinfo(mci->mci_in, SM_IO_WHAT_FD, NULL);
+			BLACKLIST_NOTIFY(BLACKLIST_AUTH_OK, fd, "AUTH OK");
 			mci->mci_sasl_auth = true;
-		else if (result == EX_TEMPFAIL || result == EX_NOPERM)
+		} else if (result == EX_TEMPFAIL || result == EX_NOPERM)
 		{
 			mci->mci_saslcap = removemech((mci->mci_sai)[SASL_MECH],
 						      mci->mci_saslcap,
