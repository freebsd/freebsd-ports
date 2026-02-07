--- src/server.c.orig	1998-11-10 04:15:31 UTC
+++ src/server.c
@@ -62,8 +62,8 @@ char	*ptarget;		/* pointer to end of target name */
 int	catname = 0;		/* cat name to target name */
 char	*sptarget[32];		/* stack of saved ptarget's for directories */
 char   *fromhost = NULL;	/* Client hostname */
-static long min_freespace = 0;	/* Minimium free space on a filesystem */
-static long min_freefiles = 0;	/* Minimium free # files on a filesystem */
+static int64_t min_freespace = 0; /* Minimium free space on a filesystem */
+static int64_t min_freefiles = 0; /* Minimium free # files on a filesystem */
 int	oumask;			/* Old umask */
 
 /*
@@ -645,8 +645,8 @@ static void query(name)
 	case S_IFLNK:
 	case S_IFDIR:
 	case S_IFREG:
-		(void) sendcmd(QC_YES, "%ld %ld %o %s %s",
-			       (long) stb.st_size, 
+		(void) sendcmd(QC_YES, "%lld %ld %o %s %s",
+			       (long long) stb.st_size, 
 			       stb.st_mtime, 
 			       stb.st_mode & 07777,
 			       getusername(stb.st_uid, target, options), 
@@ -767,9 +767,9 @@ static void recvfile(new, opts, mode, owner, group, mt
 	/*
 	 * Create temporary file
 	 */
-	if ((f = creat(new, mode)) < 0) {
+	if ((f = open(new, O_CREAT|O_TRUNC|O_WRONLY|O_EXCL, mode)) < 0) {
 		if (errno != ENOENT || chkparent(new, opts) < 0 ||
-		    (f = creat(new, mode)) < 0) {
+		    (f = open(new, O_CREAT|O_TRUNC|O_WRONLY|O_EXCL, mode)) < 0) {
 			error("%s: create failed: %s", new, SYSERR);
 			(void) unlink(new);
 			return;
@@ -783,13 +783,13 @@ static void recvfile(new, opts, mode, owner, group, mt
 	wrerr = 0;
 	olderrno = 0;
 	for (i = 0; i < size; i += BUFSIZ) {
-		int amt = BUFSIZ;
+		off_t amt = BUFSIZ;
 
 		cp = buf;
 		if (i + amt > size)
 			amt = size - i;
 		do {
-			int j;
+			ssize_t j;
 
 			j = readrem(cp, amt);
 			if (j <= 0) {
@@ -1245,18 +1245,35 @@ static void hardlink(cmd)
 		return;
 	}
 
-	oldname = strtok(cp, " ");
-	if (oldname == NULL) {
-		error("hardlink: oldname name not delimited");
-		return;
-	}
+{ unsigned int len;
 
-	newname = strtok((char *)NULL, " ");
-	if (newname == NULL) {
-		error("hardlink: new name not specified");
-		return;
-	}
+  if( *( cp += strspn( cp, " " ) ) == '\0' ) {
+    error("hardlink: oldnamelen name not found");
+    return;
+  }
 
+  len = strtoul( cp, &cp, 10 );
+
+  if( *( cp += strspn( cp, " " ) ) == '\0' ) {
+    error("hardlink: oldname not found");
+    return;
+  }
+  oldname = cp;
+  if( strlen( cp ) < len + 2 ) {
+    error("hardlink: oldname too short or nothing following found");
+    return;
+  }
+  cp += len;
+  *cp++ = '\0';
+
+  if( *( cp += strspn( cp, " " ) ) == '\0' ) {
+    error("hardlink: newname not found");
+    return;
+  }
+
+  newname = cp;
+}
+
 	if (exptilde(expbuf, oldname) == NULL) {
 		error("hardlink: tilde expansion failed");
 		return;
@@ -1306,6 +1323,7 @@ static void setconfig(cmd)
 {
 	register char *cp = cmd;
 	char *estr;
+	const char *errstr;
 
 	switch (*cp++) {
 	case SC_HOSTNAME:	/* Set hostname */
@@ -1322,19 +1340,15 @@ static void setconfig(cmd)
 		break;
 
 	case SC_FREESPACE: 	/* Minimium free space */
-		if (!isdigit(*cp)) {
-			fatalerr("Expected digit, got '%s'.", cp);
-			return;
-		}
-		min_freespace = (unsigned long) atoi(cp);
+		min_freespace = (int64_t)strtonum(cp, 0, LLONG_MAX, &errstr);
+		if (errstr)
+			fatalerr("Minimum free space is %s: '%s'", errstr, optarg);
 		break;
 
 	case SC_FREEFILES: 	/* Minimium free files */
-		if (!isdigit(*cp)) {
-			fatalerr("Expected digit, got '%s'.", cp);
-			return;
-		}
-		min_freefiles = (unsigned long) atoi(cp);
+		min_freefiles = (int64_t)strtonum(cp, 0, LLONG_MAX, &errstr);
+		if (errstr)
+			fatalerr("Minimum free files is %s: '%s'", errstr, optarg);
 		break;
 
 	case SC_LOGGING:	/* Logging options */
@@ -1364,7 +1378,7 @@ static void recvit(cmd, type)
 	time_t mtime, atime;
 	char *owner, *group, *file;
 	char new[MAXPATHLEN];
-	long freespace = -1, freefiles = -1;
+	int64_t freespace = -1, freefiles = -1;
 	char *cp = cmd;
 
 	/*
@@ -1388,7 +1402,7 @@ static void recvit(cmd, type)
 	/*
 	 * Get file size
 	 */
-	size = strtol(cp, &cp, 10);
+	size = (off_t) strtoll(cp, &cp, 10);
 	if (*cp++ != ' ') {
 		error("recvit: size not delimited");
 		return;
@@ -1397,7 +1411,7 @@ static void recvit(cmd, type)
 	/*
 	 * Get modification time
 	 */
-	mtime = strtol(cp, &cp, 10);
+	mtime = (time_t) strtol(cp, &cp, 10);
 	if (*cp++ != ' ') {
 		error("recvit: mtime not delimited");
 		return;
@@ -1441,8 +1455,8 @@ static void recvit(cmd, type)
 	}
 
 	debugmsg(DM_MISC,
-		 "recvit: opts = %04o mode = %04o size = %d mtime = %d",
-		 opts, mode, size, mtime);
+		 "recvit: opts = %04o mode = %04o size = %lld mtime = %d",
+		 opts, mode, (long long) size, mtime);
 	debugmsg(DM_MISC,
        "recvit: owner = '%s' group = '%s' file = '%s' catname = %d isdir = %d",
 		 owner, group, file, catname, (type == S_IFDIR) ? 1 : 0);
@@ -1486,7 +1500,7 @@ static void recvit(cmd, type)
 	 */
 	if (min_freespace || min_freefiles) {
 		/* Convert file size to kilobytes */
-		long fsize = (long) (size / 1024);
+		int64_t fsize = (int64_t)size / 1024;
 
 		if (getfilesysinfo(target, &freespace, &freefiles) != 0)
 			return;
@@ -1498,15 +1512,15 @@ static void recvit(cmd, type)
 		if (min_freespace && (freespace >= 0) && 
 		    (freespace - fsize < min_freespace)) {
 			error(
-		     "%s: Not enough free space on filesystem: min %d free %d",
-			      target, min_freespace, freespace);
+		     "%s: Not enough free space on filesystem: min %lld "
+		     "free %lld", target, min_freespace, freespace);
 			return;
 		}
 		if (min_freefiles && (freefiles >= 0) &&
 		    (freefiles - 1 < min_freefiles)) {
 			error(
-		     "%s: Not enough free files on filesystem: min %d free %d",
-			      target, min_freefiles, freefiles);
+		     "%s: Not enough free files on filesystem: min %lld free "
+		     "%lld", target, min_freefiles, freefiles);
 			return;
 		}
 	}
