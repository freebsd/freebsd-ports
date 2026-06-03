--- mail.local/mail.local.c.orig	2026-03-09 16:19:10 UTC
+++ mail.local/mail.local.c
@@ -154,6 +154,8 @@ bool	BounceQuota = false;		/* permanent error when ove
 bool	HoldErrs = false;		/* Hold errors in ErrBuf */
 bool	LMTPMode = false;
 bool	BounceQuota = false;		/* permanent error when over quota */
+bool	NoBiff = false;
+bool	NoFsync = false;
 bool	CloseMBDB = false;
 char	*HomeMailFile = NULL;		/* store mail in homedir */
 
@@ -234,12 +236,12 @@ main(int argc, char *argv[])
 
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
@@ -249,6 +251,10 @@ main(int argc, char *argv[])
 			EightBitMime = false;
 			break;
 
+		  case 'B':
+			NoBiff = true;
+			break;
+
 		  case 'b':		/* bounce mail when over quota. */
 			BounceQuota = true;
 			break;
@@ -358,6 +364,10 @@ main(int argc, char *argv[])
 #endif
 			break;
 
+		  case 's':
+			NoFsync = true;
+			break;
+
 		  case '?':
 		  default:
 			usage();
@@ -367,7 +377,8 @@ main(int argc, char *argv[])
 	argv += optind;
 
 	/* initialize biff structures */
-	notifybiff(NULL);
+	if (!NoBiff)
+		notifybiff(NULL);
 
 	err = sm_mbdb_initialize(mbdbname);
 	if (err != EX_OK)
@@ -1290,6 +1301,7 @@ tryagain:
 
 	/* Get the starting offset of the new message */
 	curoff = lseek(mbfd, (off_t) 0, SEEK_END);
+	if (!NoBiff)
 	(void) sm_snprintf(biffmsg, sizeof(biffmsg), "%s@%lld\n",
 			   name, (LONGLONG_T) curoff);
 
@@ -1352,7 +1364,7 @@ tryagain:
 	}
 
 	/* Flush to disk, don't wait for update. */
-	if (fsync(mbfd) < 0)
+	if (!NoFsync && fsync(mbfd) < 0)
 	{
 		mailerr("450 4.2.0", "Sync %s: %s", path, sm_errstring(errno));
 err3:
@@ -1423,7 +1435,7 @@ err0:
 		/* Attempt to truncate back to pre-write size */
 		goto err3;
 	}
-	else
+	else if (!NoBiff)
 		notifybiff(biffmsg);
 
 	if (
@@ -1604,9 +1616,9 @@ usage(void)
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
