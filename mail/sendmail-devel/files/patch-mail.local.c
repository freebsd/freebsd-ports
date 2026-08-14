--- mail.local/mail.local.c.orig	2026-03-17 06:40:58 UTC
+++ mail.local/mail.local.c
@@ -154,6 +154,8 @@ bool	BounceQuota = false;		/* permanent error when ove
 bool	HoldErrs = false;		/* Hold errors in ErrBuf */
 bool	LMTPMode = false;
 bool	BounceQuota = false;		/* permanent error when over quota */
+bool	NoBiff = false;
+bool	NoFsync = false;
 bool	CloseMBDB = false;
 char	*HomeMailFile = NULL;		/* store mail in homedir */
 
@@ -232,12 +234,12 @@ main(int argc, char *argv[])
 
 	/* HACK: add U to all options - this should be only for USE_EAI */
 #if HASHSPOOL
-	while ((ch = getopt(argc, argv, "7bdD:f:h:r:lH:p:nUV")) != -1)
+	while ((ch = getopt(argc, argv, "7bBdD:f:h:r:lH:p:nUV")) != -1)
 #else /* HASHSPOOL */
 # if _FFR_SPOOL_PATH
-	while ((ch = getopt(argc, argv, "7bdD:f:h:r:lp:UV")) != -1)
+	while ((ch = getopt(argc, argv, "7bBdD:f:h:r:lp:UV")) != -1)
 # else
-	while ((ch = getopt(argc, argv, "7bdD:f:h:r:lUV")) != -1)
+	while ((ch = getopt(argc, argv, "7bBdD:f:h:r:lUV")) != -1)
 # endif
 #endif /* HASHSPOOL */
 	{
@@ -247,6 +249,10 @@ main(int argc, char *argv[])
 			EightBitMime = false;
 			break;
 
+		  case 'B':
+			NoBiff = true;
+			break;
+
 		  case 'b':		/* bounce mail when over quota. */
 			BounceQuota = true;
 			break;
@@ -356,6 +362,10 @@ main(int argc, char *argv[])
 #endif
 			break;
 
+		  case 's':
+			NoFsync = true;
+			break;
+
 		  case '?':
 		  default:
 			usage();
@@ -365,7 +375,8 @@ main(int argc, char *argv[])
 	argv += optind;
 
 	/* initialize biff structures */
-	notifybiff(NULL);
+	if (!NoBiff)
+		notifybiff(NULL);
 
 	err = sm_mbdb_initialize(mbdbname);
 	if (err != EX_OK)
@@ -1288,6 +1299,7 @@ tryagain:
 
 	/* Get the starting offset of the new message */
 	curoff = lseek(mbfd, (off_t) 0, SEEK_END);
+	if (!NoBiff)
 	(void) sm_snprintf(biffmsg, sizeof(biffmsg), "%s@%lld\n",
 			   name, (LONGLONG_T) curoff);
 
@@ -1350,7 +1362,7 @@ tryagain:
 	}
 
 	/* Flush to disk, don't wait for update. */
-	if (fsync(mbfd) < 0)
+	if (!NoFsync && fsync(mbfd) < 0)
 	{
 		mailerr("450 4.2.0", "Sync %s: %s", path, sm_errstring(errno));
 err3:
@@ -1421,7 +1433,7 @@ err0:
 		/* Attempt to truncate back to pre-write size */
 		goto err3;
 	}
-	else
+	else if (!NoBiff)
 		notifybiff(biffmsg);
 
 	if (
@@ -1602,9 +1614,9 @@ usage(void)
 {
 	/* XXX add U to options for USE_EAI */
 #if _FFR_SPOOL_PATH
-	mailerr(NULL, "usage: mail.local [-7] [-b] [-d] [-l] [-f from|-r from] [-h filename] [-p path] user ...");
+	mailerr(NULL, "usage: mail.local [-7] [-b] [-B] [-d] [-l] [-f from|-r from] [-h filename] [-p path] user ...");
 #else
-	mailerr(NULL, "usage: mail.local [-7] [-b] [-d] [-l] [-f from|-r from] [-h filename] user ...");
+	mailerr(NULL, "usage: mail.local [-7] [-b] [-B] [-d] [-l] [-f from|-r from] [-h filename] user ...");
 #endif
 	sm_exit(EX_USAGE);
 }
