--- mail.local/mail.local.c.orig	2025-06-27 17:57:30 UTC
+++ mail.local/mail.local.c
@@ -154,6 +154,8 @@ bool	BounceQuota = false;		/* permanent error when ove
 bool	HoldErrs = false;		/* Hold errors in ErrBuf */
 bool	LMTPMode = false;
 bool	BounceQuota = false;		/* permanent error when over quota */
+bool	NoBiff = false;
+bool	NoFsync = false;
 bool	CloseMBDB = false;
 char	*HomeMailFile = NULL;		/* store mail in homedir */
 
@@ -237,12 +239,12 @@ main(argc, argv)
 
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
@@ -252,6 +254,10 @@ main(argc, argv)
 			EightBitMime = false;
 			break;
 
+		  case 'B':
+			NoBiff = true;
+			break;
+
 		  case 'b':		/* bounce mail when over quota. */
 			BounceQuota = true;
 			break;
@@ -361,6 +367,10 @@ main(argc, argv)
 #endif
 			break;
 
+		  case 's':
+			NoFsync = true;
+			break;
+
 		  case '?':
 		  default:
 			usage();
@@ -370,7 +380,8 @@ main(argc, argv)
 	argv += optind;
 
 	/* initialize biff structures */
-	notifybiff(NULL);
+	if (!NoBiff)
+		notifybiff(NULL);
 
 	err = sm_mbdb_initialize(mbdbname);
 	if (err != EX_OK)
@@ -1300,6 +1311,7 @@ tryagain:
 
 	/* Get the starting offset of the new message */
 	curoff = lseek(mbfd, (off_t) 0, SEEK_END);
+	if (!NoBiff)
 	(void) sm_snprintf(biffmsg, sizeof(biffmsg), "%s@%lld\n",
 			   name, (LONGLONG_T) curoff);
 
@@ -1362,7 +1374,7 @@ tryagain:
 	}
 
 	/* Flush to disk, don't wait for update. */
-	if (fsync(mbfd) < 0)
+	if (!NoFsync && fsync(mbfd) < 0)
 	{
 		mailerr("450 4.2.0", "Sync %s: %s", path, sm_errstring(errno));
 err3:
@@ -1433,7 +1445,7 @@ err0:
 		/* Attempt to truncate back to pre-write size */
 		goto err3;
 	}
-	else
+	else if (!NoBiff)
 		notifybiff(biffmsg);
 
 	if (
@@ -1617,9 +1629,9 @@ usage()
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
