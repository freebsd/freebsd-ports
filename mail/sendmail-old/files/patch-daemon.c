--- sendmail/daemon.c	2001/08/01 03:19:45	1.1.1.3.2.6
+++ sendmail/daemon.c	2001/09/09 19:31:37
@@ -1877,17 +1877,6 @@
 gothostent:
 		if (hp == NULL)
 		{
-# if NAMED_BIND
-			/* check for name server timeouts */
-			if (errno == ETIMEDOUT || h_errno == TRY_AGAIN ||
-			    (errno == ECONNREFUSED && UseNameServer))
-			{
-				save_errno = errno;
-				mci_setstat(mci, EX_TEMPFAIL, "4.4.3", NULL);
-				errno = save_errno;
-				return EX_TEMPFAIL;
-			}
-# endif /* NAMED_BIND */
 # if NETINET6
 			/*
 			**  Try v6 first, then fall back to v4.
@@ -1903,6 +1892,17 @@
 			if (v6found)
 				goto v6tempfail;
 # endif /* NETINET6 */
+# if NAMED_BIND
+			/* check for name server timeouts */
+			if (errno == ETIMEDOUT || h_errno == TRY_AGAIN ||
+			    (errno == ECONNREFUSED && UseNameServer))
+			{
+				save_errno = errno;
+				mci_setstat(mci, EX_TEMPFAIL, "4.4.3", NULL);
+				errno = save_errno;
+				return EX_TEMPFAIL;
+			}
+# endif /* NAMED_BIND */
 			save_errno = errno;
 			mci_setstat(mci, EX_NOHOST, "5.1.2", NULL);
 			errno = save_errno;

