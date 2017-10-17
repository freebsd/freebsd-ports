--- sendmail/usersmtp.c.orig	2014-12-05 10:42:28.000000000 -0500
+++ sendmail/usersmtp.c	2016-06-12 18:35:25.940865000 -0400
@@ -1825,6 +1825,10 @@
 
 		if (saslresult != SASL_OK && saslresult != SASL_CONTINUE)
 		{
+#ifdef USE_BLACKLIST
+			int fd = sm_io_getinfo(mci->mci_in, SM_IO_WHAT_FD, NULL);
+			blacklist_notify(1, fd, "AUTH FAIL");
+#endif
 			if (tTd(95, 5))
 				sm_dprintf("AUTH FAIL=%s (%d)\n",
 					sasl_errstring(saslresult, NULL, NULL),
@@ -1970,9 +1974,13 @@
 	do
 	{
 		result = attemptauth(m, mci, e, &(mci->mci_sai));
-		if (result == EX_OK)
+		if (result == EX_OK) {
+#ifdef USE_BLACKLIST
+			int fd = sm_io_getinfo(mci->mci_in, SM_IO_WHAT_FD, NULL);
+			blacklist_notify(0, fd, "AUTH OK");
+#endif
 			mci->mci_sasl_auth = true;
-		else if (result == EX_TEMPFAIL || result == EX_NOPERM)
+		} else if (result == EX_TEMPFAIL || result == EX_NOPERM)
 		{
 			mci->mci_saslcap = removemech((mci->mci_sai)[SASL_MECH],
 						      mci->mci_saslcap,
