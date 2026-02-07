--- src/message.c.orig	1998-11-10 04:13:30 UTC
+++ src/message.c
@@ -462,8 +462,8 @@ static void msgsendnotify(msgfac, mtype, flags, msgbuf
 		return;
 
 	if (!msgfac->mf_fptr) {
-		register char *cp;
-		char *getenv();
+		const char *cp;
+		int	fd;
 
 		/*
 		 * Create and open a new temporary file
@@ -475,8 +475,8 @@ static void msgsendnotify(msgfac, mtype, flags, msgbuf
 		(void) sprintf(tempfile, "%s/%s", cp, _RDIST_TMP);
 
 		msgfac->mf_filename = tempfile;
-		(void) mktemp(msgfac->mf_filename);
-		if ((msgfac->mf_fptr = fopen(msgfac->mf_filename, "w"))==NULL)
+		fd = mkstemp(tempfile);
+		if (fd == -1 || (msgfac->mf_fptr = fdopen(fd, "w"))==NULL)
 			fatalerr("Cannot open notify file for writing: %s: %s.",
 			      msgfac->mf_filename, SYSERR);
 		debugmsg(DM_MISC, "Created notify temp file '%s'",
@@ -513,7 +513,7 @@ extern void checkhostname()
  */
 static void _message(flags, msgbuf)
 	int flags;
-	char *msgbuf;
+	const char *msgbuf;
 {
 	register int i, x;
 	register char *cp;
