--- src/client.c.orig	1998-11-10 04:08:47 UTC
+++ src/client.c
@@ -356,16 +356,16 @@ static int sendhardlink(opts, lp, rname, destdir)
 		 rname, lp->pathname, lp->src, lp->target);
 		 
 	if (*lp->target == CNULL)
-		(void) sendcmd(C_RECVHARDLINK, "%o %s %s", 
-			       opts, lp->pathname, rname);
+		(void) sendcmd(C_RECVHARDLINK, "%o %d %s %s", 
+			       opts, strlen(lp->pathname), lp->pathname, rname);
 	else {
 		lname = buff;
 		strcpy(lname, remfilename(lp->src, lp->target, 
 					  lp->pathname, rname, 
 					  destdir));
 		debugmsg(DM_MISC, "sendhardlink: lname=%s\n", lname);
-		(void) sendcmd(C_RECVHARDLINK, "%o %s %s", 
-			       opts, lname, rname);
+		(void) sendcmd(C_RECVHARDLINK, "%o %d %s %s", 
+			       opts, strlen(lname), lname, rname);
 	}
 
 	return(response());
@@ -399,9 +399,9 @@ static int sendfile(rname, opts, stb, user, group, des
 	/*
 	 * Send file info
 	 */
-	(void) sendcmd(C_RECVREG, "%o %04o %ld %ld %ld %s %s %s", 
+	(void) sendcmd(C_RECVREG, "%o %04o %lld %ld %ld %s %s %s", 
 		       opts, stb->st_mode & 07777, 
-		       (long) stb->st_size, 
+		       (long long) stb->st_size, 
 		       stb->st_mtime, stb->st_atime,
 		       user, group, rname);
 	if (response() < 0) {
@@ -409,8 +409,8 @@ static int sendfile(rname, opts, stb, user, group, des
 		return(-1);
 	}
 
-	debugmsg(DM_MISC, "Send file '%s' %d bytes\n", 
-		 rname, (long) stb->st_size);
+	debugmsg(DM_MISC, "Send file '%s' %ld bytes\n", 
+		 rname, (long long) stb->st_size);
 
 	/*
 	 * Set remote time out alarm handler.
@@ -661,9 +661,9 @@ static int sendlink(rname, opts, stb, user, group, des
 	/*
 	 * Gather and send basic link info
 	 */
-	(void) sendcmd(C_RECVSYMLINK, "%o %04o %ld %ld %ld %s %s %s", 
+	(void) sendcmd(C_RECVSYMLINK, "%o %04o %lld %ld %ld %s %s %s", 
 		       opts, stb->st_mode & 07777, 
-		       (long) stb->st_size, 
+		       (long long) stb->st_size, 
 		       stb->st_mtime, stb->st_atime,
 		       user, group, rname);
 	if (response() < 0)
@@ -761,7 +761,7 @@ static int update(rname, opts, statp)
 	unsigned short rmode;
 	char *owner = NULL, *group = NULL;
 	int done, n;
-	u_char *cp;
+	char *cp;
 
 	debugmsg(DM_CALL, "update(%s, 0x%x, 0x%x)\n", rname, opts, statp);
 
@@ -843,7 +843,7 @@ static int update(rname, opts, statp)
 	/*
 	 * Parse size
 	 */
-	size = strtol(cp, &cp, 10);
+	size = strtoll(cp, &cp, 10);
 	if (*cp++ != ' ') {
 		error("update: size not delimited");
 		return(US_NOTHING);
@@ -895,8 +895,8 @@ static int update(rname, opts, statp)
 
 	debugmsg(DM_MISC, "update(%s,) local mode %04o remote mode %04o\n", 
 		 rname, lmode, rmode);
-	debugmsg(DM_MISC, "update(%s,) size %d mtime %d owner '%s' grp '%s'\n",
-		 rname, (int) size, mtime, owner, group);
+	debugmsg(DM_MISC, "update(%s,) size %lld mtime %d owner '%s' grp '%s'\n",
+		 rname, (long long) size, mtime, owner, group);
 
 	if (statp->st_mtime != mtime) {
 		if (statp->st_mtime < mtime && IS_ON(opts, DO_YOUNGER)) {
@@ -922,8 +922,8 @@ static int update(rname, opts, statp)
 	}
 
 	if (statp->st_size != size) {
-		debugmsg(DM_MISC, "size does not match (%d != %d).\n",
-			 (int) statp->st_size, size);
+		debugmsg(DM_MISC, "size does not match (%lld != %lld).\n",
+			 (long long) statp->st_size, (long long)size);
 		return(US_OUTDATE);
 	} 
 
