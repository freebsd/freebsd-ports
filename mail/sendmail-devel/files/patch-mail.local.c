--- mail.local/mail.local.c.orig	2020-04-30 11:52:48 UTC
+++ mail.local/mail.local.c
@@ -153,6 +153,8 @@ int	ExitVal = EX_OK;		/* sysexits.h error value. */
 bool	HoldErrs = false;		/* Hold errors in ErrBuf */
 bool	LMTPMode = false;
 bool	BounceQuota = false;		/* permanent error when over quota */
+bool	NoBiff = false;
+bool	NoFsync = false;
 bool	CloseMBDB = false;
 char	*HomeMailFile = NULL;		/* store mail in homedir */
 
@@ -234,12 +236,12 @@ main(argc, argv)
 		sm_exit(EX_CONFIG);
 	}
 #if HASHSPOOL
-	while ((ch = getopt(argc, argv, "7bdD:f:h:r:lH:p:n")) != -1)
+	while ((ch = getopt(argc, argv, "7bBdD:f:h:r:lsH:p:n")) != -1)
 #else /* HASHSPOOL */
 #  if _FFR_SPOOL_PATH
-	while ((ch = getopt(argc, argv, "7bdD:f:h:r:lp:")) != -1)
+	while ((ch = getopt(argc, argv, "7bBdD:f:h:r:lsp:")) != -1)
 #  else
-	while ((ch = getopt(argc, argv, "7bdD:f:h:r:l")) != -1)
+	while ((ch = getopt(argc, argv, "7bBdD:f:h:r:ls")) != -1)
 #  endif
 #endif /* HASHSPOOL */
 	{
@@ -249,6 +251,10 @@ main(argc, argv)
 			EightBitMime = false;
 			break;
 
+		  case 'B':
+			NoBiff = true;
+			break;
+
 		  case 'b':		/* bounce mail when over quota. */
 			BounceQuota = true;
 			break;
@@ -342,6 +348,10 @@ main(argc, argv)
 			break;
 #endif /* HASHSPOOL || _FFR_SPOOL_PATH */
 
+		  case 's':
+			NoFsync = true;
+			break;
+
 		  case '?':
 		  default:
 			usage();
@@ -351,7 +361,8 @@ main(argc, argv)
 	argv += optind;
 
 	/* initialize biff structures */
-	notifybiff(NULL);
+	if (!NoBiff)
+		notifybiff(NULL);
 
 	err = sm_mbdb_initialize(mbdbname);
 	if (err != EX_OK)
@@ -1273,6 +1284,7 @@ tryagain:
 
 	/* Get the starting offset of the new message */
 	curoff = lseek(mbfd, (off_t) 0, SEEK_END);
+	if (!NoBiff)
 	(void) sm_snprintf(biffmsg, sizeof(biffmsg), "%s@%lld\n",
 			   name, (LONGLONG_T) curoff);
 
@@ -1335,7 +1347,7 @@ tryagain:
 	}
 
 	/* Flush to disk, don't wait for update. */
-	if (fsync(mbfd) < 0)
+	if (!NoFsync && fsync(mbfd) < 0)
 	{
 		mailerr("450 4.2.0", "%s: %s", path, sm_errstring(errno));
 err3:
@@ -1402,7 +1414,7 @@ err0:		(void) setreuid(0, 0);
 		/* Attempt to truncate back to pre-write size */
 		goto err3;
 	}
-	else
+	else if (!NoBiff)
 		notifybiff(biffmsg);
 
 	if (setreuid(0, 0) < 0)
@@ -1582,9 +1594,9 @@ usage()
 {
 	ExitVal = EX_USAGE;
 # if _FFR_SPOOL_PATH
-	mailerr(NULL, "usage: mail.local [-7] [-b] [-d] [-l] [-f from|-r from] [-h filename] [-p path] user ...");
+	mailerr(NULL, "usage: mail.local [-7] [-b] [-B] [-d] [-l] [-s] [-f from|-r from] [-h filename] [-p path] user ...");
 # else
-	mailerr(NULL, "usage: mail.local [-7] [-b] [-d] [-l] [-f from|-r from] [-h filename] user ...");
+	mailerr(NULL, "usage: mail.local [-7] [-b] [-B] [-d] [-l] [-s] [-f from|-r from] [-h filename] user ...");
 # endif
 	sm_exit(ExitVal);
 }
