--- src/server.c.orig	2001-10-22 13:29:22.000000000 -0700
+++ src/server.c	2024-03-19 19:42:42.143575000 -0700
@@ -91,8 +91,8 @@
 int	catname = 0;		/* cat name to target name */
 char	*sptarget[128];		/* stack of saved ptarget's for directories */
 char   *fromhost = NULL;	/* Client hostname */
-static long min_freespace = 0;	/* Minimium free space on a filesystem */
-static long min_freefiles = 0;	/* Minimium free # files on a filesystem */
+static int64_t min_freespace = 0; /* Minimium free space on a filesystem */
+static int64_t min_freefiles = 0; /* Minimium free # files on a filesystem */
 int	oumask;			/* Old umask */
 
 /*
@@ -172,7 +172,7 @@
 /*
  * Set mode of a file
  */
-static int setmode(file, fd, mode, link)
+static int rdist_setmode(file, fd, mode, link)
 	char *file;
 	int fd;
 	int mode;
@@ -355,7 +355,7 @@
 			mode &= ~S_ISGID;
 		}
 	}
-	(void) setmode(file, fd, mode, S_ISLNK(st.st_mode));
+	(void) rdist_setmode(file, fd, mode, S_ISLNK(st.st_mode));
 
 	return(0);
 }
@@ -921,13 +921,13 @@
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
 
 			if (rem_rz)
 			    j = readremz(cp, amt);
@@ -1538,6 +1538,7 @@
 {
 	register char *cp = cmd;
 	char *estr;
+	const char *errstr;
 
 	switch (*cp++) {
 	case SC_HOSTNAME:	/* Set hostname */
@@ -1554,19 +1555,15 @@
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
@@ -1608,7 +1605,7 @@
 	char new[MAXPATHLEN];
 	int newfd = -1;
 	char fileb[MAXPATHLEN];
-	long freespace = -1, freefiles = -1;
+	int64_t freespace = -1, freefiles = -1;
 	char *cp = cmd;
 	char *name;
 
@@ -1633,7 +1630,7 @@
 	/*
 	 * Get file size
 	 */
-	size = strtol(cp, &cp, 10);
+	size = (off_t) strtoll(cp, &cp, 10);
 	if (*cp++ != ' ') {
 		error("recvit: size not delimited");
 		return;
@@ -1642,7 +1639,7 @@
 	/*
 	 * Get modification time
 	 */
-	mtime = strtol(cp, &cp, 10);
+	mtime = (time_t) strtol(cp, &cp, 10);
 	if (*cp++ != ' ') {
 		error("recvit: mtime not delimited");
 		return;
@@ -1692,8 +1689,8 @@
 	file = fileb;
 
 	debugmsg(DM_MISC,
-		 "recvit: opts = %04o mode = %04o size = %d mtime = %d",
-		 opts, mode, size, mtime);
+		 "recvit: opts = %04o mode = %04o size = %lld mtime = %d",
+		 opts, mode, (long long) size, mtime);
 	debugmsg(DM_MISC,
        "recvit: owner = '%s' group = '%s' file = '%s' catname = %d isdir = %d",
 		 owner, group, file, catname, (type == S_IFDIR) ? 1 : 0);
@@ -1749,7 +1746,7 @@
 	 */
 	if (min_freespace || min_freefiles) {
 		/* Convert file size to kilobytes */
-		long fsize = (long) (size / 1024);
+		int64_t fsize = (int64_t)size / 1024;
 
 		if (getfilesysinfo(target, &freespace, &freefiles) != 0) {
 		    	(void) close(newfd);
@@ -1764,7 +1761,7 @@
 		if (min_freespace && (freespace >= 0) && 
 		    (freespace - fsize < min_freespace)) {
 			error(
-		     "%s: Not enough free space on filesystem: min %d free %d",
+		     "%s: Not enough free space on filesystem: min %lld free %lld",
 			      target, min_freespace, freespace);
 		    	(void) close(newfd);
 		    	(void) unlink(new);
@@ -1773,7 +1770,7 @@
 		if (min_freefiles && (freefiles >= 0) &&
 		    (freefiles - 1 < min_freefiles)) {
 			error(
-		     "%s: Not enough free files on filesystem: min %d free %d",
+		     "%s: Not enough free files on filesystem: min %lld free %lld",
 			      target, min_freefiles, freefiles);
 		    	(void) close(newfd);
 		    	(void) unlink(new);
