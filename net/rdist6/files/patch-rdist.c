--- ./src/rdist.c.ORI	2012-06-12 07:35:16.000000000 +0200
+++ ./src/rdist.c	2012-06-12 07:49:18.000000000 +0200
@@ -62,8 +62,8 @@
 char   	       *distfile = NULL;		/* Name of distfile to use */
 int     	maxchildren = MAXCHILDREN;	/* Max no of concurrent PIDs */
 int		nflag = 0;			/* Say without doing */
-long		min_freespace = 0;		/* Min filesys free space */
-long		min_freefiles = 0;		/* Min filesys free # files */
+int64_t		min_freespace = 0;		/* Min filesys free space */
+int64_t		min_freefiles = 0;		/* Min filesys free # files */
 FILE   	       *fin = NULL;			/* Input file pointer */
 struct group   *gr = NULL;			/* Static area for getgrent */
 char		localmsglist[] = "stdout=all:notify=all:syslog=nerror,ferror";
@@ -109,6 +109,7 @@
 	register char *cp;
 	int cmdargs = 0;
 	int c;
+	const char *errstr;
 
 	/*
 	 * We initialize progname here instead of init() because
@@ -178,10 +179,20 @@
 				error("\"%s\" is not a number.", optarg);
 				usage();
 			}
-			if (c == 'a')
-				min_freespace = atoi(optarg);
-			else if (c == 'A')
-				min_freefiles = atoi(optarg);
+			if (c == 'a') {
+				min_freespace = (int64_t)strtonum(optarg,
+					0, LLONG_MAX, &errstr);
+				if (errstr)
+					fatalerr("Minimum free space is %s: "
+						 "'%s'", errstr, optarg);
+			}
+			else if (c == 'A') {
+				min_freefiles = (int64_t)strtonum(optarg,
+					0, LLONG_MAX, &errstr);
+				if (errstr)
+					fatalerr("Minimum free files is %s: "
+						 "'%s'", errstr, optarg);
+			}
 			else if (c == 'M')
 				maxchildren = atoi(optarg);
 			else if (c == 't')
--- ./src/server.c.ORI	2012-06-12 07:35:16.000000000 +0200
+++ ./src/server.c	2012-06-12 08:14:41.651950502 +0200
@@ -62,8 +62,8 @@
 int	catname = 0;		/* cat name to target name */
 char	*sptarget[32];		/* stack of saved ptarget's for directories */
 char   *fromhost = NULL;	/* Client hostname */
-static long min_freespace = 0;	/* Minimium free space on a filesystem */
-static long min_freefiles = 0;	/* Minimium free # files on a filesystem */
+static int64_t min_freespace = 0; /* Minimium free space on a filesystem */
+static int64_t min_freefiles = 0; /* Minimium free # files on a filesystem */
 int	oumask;			/* Old umask */
 
 /*
@@ -645,8 +645,8 @@
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
@@ -783,13 +783,13 @@
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
@@ -1306,6 +1306,7 @@
 {
 	register char *cp = cmd;
 	char *estr;
+	const char *errstr;
 
 	switch (*cp++) {
 	case SC_HOSTNAME:	/* Set hostname */
@@ -1322,19 +1323,15 @@
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
@@ -1364,7 +1361,7 @@
 	time_t mtime, atime;
 	char *owner, *group, *file;
 	char new[MAXPATHLEN];
-	long freespace = -1, freefiles = -1;
+	int64_t freespace = -1, freefiles = -1;
 	char *cp = cmd;
 
 	/*
@@ -1388,7 +1385,7 @@
 	/*
 	 * Get file size
 	 */
-	size = strtol(cp, &cp, 10);
+	size = (off_t) strtoll(cp, &cp, 10);
 	if (*cp++ != ' ') {
 		error("recvit: size not delimited");
 		return;
@@ -1397,7 +1394,7 @@
 	/*
 	 * Get modification time
 	 */
-	mtime = strtol(cp, &cp, 10);
+	mtime = (time_t) strtol(cp, &cp, 10);
 	if (*cp++ != ' ') {
 		error("recvit: mtime not delimited");
 		return;
@@ -1441,8 +1438,8 @@
 	}
 
 	debugmsg(DM_MISC,
-		 "recvit: opts = %04o mode = %04o size = %d mtime = %d",
-		 opts, mode, size, mtime);
+		 "recvit: opts = %04o mode = %04o size = %lld mtime = %d",
+		 opts, mode, (long long) size, mtime);
 	debugmsg(DM_MISC,
        "recvit: owner = '%s' group = '%s' file = '%s' catname = %d isdir = %d",
 		 owner, group, file, catname, (type == S_IFDIR) ? 1 : 0);
@@ -1486,7 +1483,7 @@
 	 */
 	if (min_freespace || min_freefiles) {
 		/* Convert file size to kilobytes */
-		long fsize = (long) (size / 1024);
+		int64_t fsize = (int64_t)size / 1024;
 
 		if (getfilesysinfo(target, &freespace, &freefiles) != 0)
 			return;
@@ -1498,15 +1495,15 @@
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
--- ./src/docmd.c.ORI	2012-06-12 07:35:16.000000000 +0200
+++ ./src/docmd.c	2012-06-12 08:11:29.000000000 +0200
@@ -102,7 +102,8 @@
 	register struct namelist *to;
 	time_t lmod;
 {
-	register int fd, len;
+	register int fd;
+	ssize_t len;
 	FILE *pf, *popen();
 	struct stat stb;
 	static char buf[BUFSIZ];
@@ -325,7 +326,7 @@
 	register char *ruser, *cp;
 	static char *cur_host = NULL;
 	extern char *locuser;
-	extern long min_freefiles, min_freespace;
+	extern int64_t min_freefiles, min_freespace;
 	extern char *remotemsglist;
 	char tuser[BUFSIZ], buf[BUFSIZ];
 	u_char respbuff[BUFSIZ];
@@ -416,13 +417,13 @@
 			return(0);
 	}
 	if (min_freespace) {
-		(void) sendcmd(C_SETCONFIG, "%c%d", SC_FREESPACE, 
+		(void) sendcmd(C_SETCONFIG, "%c%lld", SC_FREESPACE, 
 			       min_freespace);
 		if (response() < 0)
 			return(0);
 	}
 	if (min_freefiles) {
-		(void) sendcmd(C_SETCONFIG, "%c%d", SC_FREEFILES, 
+		(void) sendcmd(C_SETCONFIG, "%c%lld", SC_FREEFILES, 
 			       min_freefiles);
 		if (response() < 0)
 			return(0);
--- ./src/common.c.ORI	2012-06-12 07:35:16.000000000 +0200
+++ ./src/common.c	2012-06-12 08:01:34.000000000 +0200
@@ -379,14 +379,14 @@
  */
 static u_char rembuf[BUFSIZ];
 static u_char *remptr;
-static int remleft;
+static ssize_t remleft;
 
 #define remc() (--remleft < 0 ? remmore() : *remptr++)
 
 /*
  * Back end to remote read()
  */
-static int remread(fd, buf, bufsiz)
+static ssize_t remread(fd, buf, bufsiz)
 	int fd;
 	u_char *buf;
 	int bufsiz;
@@ -480,7 +480,7 @@
 /*
  * Non-line-oriented remote read.
  */
-readrem(p, space)
+ssize_t readrem(p, space)
 	char *p;
 	register int space;
 {
@@ -878,7 +878,7 @@
 	extern POINTER *malloc();
 
 	if ((ptr = (char *)malloc(amt)) == NULL)
-		fatalerr("Cannot malloc %d bytes of memory.", amt);
+		fatalerr("Cannot malloc %zu bytes of memory.", amt);
 
 	return(ptr);
 }
@@ -894,7 +894,7 @@
 	extern POINTER *realloc();
 
 	if ((new = (char *)realloc(baseptr, amt)) == NULL)
-		fatalerr("Cannot realloc %d bytes of memory.", amt);
+		fatalerr("Cannot realloc %zu bytes of memory.", amt);
 
 	return(new);
 }
@@ -910,7 +910,7 @@
 	extern POINTER *calloc();
 
 	if ((ptr = (char *)calloc(num, esize)) == NULL)
-		fatalerr("Cannot calloc %d * %d = %d bytes of memory.",
+		fatalerr("Cannot calloc %zu * %zu = %zu bytes of memory.",
 		      num, esize, num * esize);
 
 	return(ptr);
--- ./src/filesys.c.ORI	2012-06-12 07:35:16.000000000 +0200
+++ ./src/filesys.c	2012-06-12 08:12:20.000000000 +0200
@@ -434,8 +434,8 @@
  */
 int getfilesysinfo(file, freespace, freefiles)
 	char *file;
-	long *freespace;
-	long *freefiles;
+	int64_t *freespace;
+	int64_t *freefiles;
 {
 #if	defined(STATFS_TYPE)
 	static statfs_t statfsbuf;
--- ./config/config-data.h.ORI	1998-11-10 04:59:47.000000000 +0100
+++ ./config/config-data.h	2012-06-12 07:55:48.000000000 +0200
@@ -58,10 +58,10 @@
  * Set default write(2) return and amount types.
  */
 #if	!defined(WRITE_RETURN_T)
-#define		WRITE_RETURN_T		int	/* What write() returns */
+#define		WRITE_RETURN_T		ssize_t	/* What write() returns */
 #endif	/* WRITE_RETURN_T */
 #if	!defined(WRITE_AMT_T)
-#define		WRITE_AMT_T		int	/* Amount to write */
+#define		WRITE_AMT_T		size_t	/* Amount to write */
 #endif	/* WRITE_AMT_T */
 
 #endif	/* __configdata_h__ */
--- ./src/client.c.ORI	2012-06-12 08:26:35.000000000 +0200
+++ ./src/client.c	2012-06-12 08:57:34.000000000 +0200
@@ -399,9 +399,9 @@
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
@@ -409,8 +409,8 @@
 		return(-1);
 	}
 
-	debugmsg(DM_MISC, "Send file '%s' %d bytes\n", 
-		 rname, (long) stb->st_size);
+	debugmsg(DM_MISC, "Send file '%s' %ld bytes\n", 
+		 rname, (long long) stb->st_size);
 
 	/*
 	 * Set remote time out alarm handler.
@@ -661,9 +661,9 @@
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
@@ -843,7 +843,7 @@
 	/*
 	 * Parse size
 	 */
-	size = strtol(cp, &cp, 10);
+	size = strtoll(cp, &cp, 10);
 	if (*cp++ != ' ') {
 		error("update: size not delimited");
 		return(US_NOTHING);
@@ -895,8 +895,8 @@
 
 	debugmsg(DM_MISC, "update(%s,) local mode %04o remote mode %04o\n", 
 		 rname, lmode, rmode);
-	debugmsg(DM_MISC, "update(%s,) size %d mtime %d owner '%s' grp '%s'\n",
-		 rname, (int) size, mtime, owner, group);
+	debugmsg(DM_MISC, "update(%s,) size %lld mtime %d owner '%s' grp '%s'\n",
+		 rname, (long long) size, mtime, owner, group);
 
 	if (statp->st_mtime != mtime) {
 		if (statp->st_mtime < mtime && IS_ON(opts, DO_YOUNGER)) {
@@ -922,8 +922,8 @@
 	}
 
 	if (statp->st_size != size) {
-		debugmsg(DM_MISC, "size does not match (%d != %d).\n",
-			 (int) statp->st_size, size);
+		debugmsg(DM_MISC, "size does not match (%lld != %lld).\n",
+			 (long long) statp->st_size, (long long)size);
 		return(US_OUTDATE);
 	} 
 
--- ./src/child.c.ORI	1998-11-10 05:18:57.000000000 +0100
+++ ./src/child.c	2012-06-12 08:58:16.000000000 +0200
@@ -189,7 +189,7 @@
 	CHILD *child;
 {
 	char rbuf[BUFSIZ];
-	int amt;
+	ssize_t amt;
 
 	debugmsg(DM_CALL, "[readchild(%s, %d, %d) start]", 
 		 child->c_name, child->c_pid, child->c_readfd);
@@ -208,7 +208,7 @@
 	 */
 	while ((amt = read(child->c_readfd, rbuf, sizeof(rbuf))) > 0) {
 		/* XXX remove these debug calls */
-		debugmsg(DM_MISC, "[readchild(%s, %d, %d) got %d bytes]", 
+		debugmsg(DM_MISC, "[readchild(%s, %d, %d) got %lld bytes]", 
 			 child->c_name, child->c_pid, child->c_readfd, amt);
 
 		(void) xwrite(fileno(stdout), rbuf, amt);
@@ -217,7 +217,7 @@
 			 child->c_name, child->c_pid, child->c_readfd);
 	}
 
-	debugmsg(DM_MISC, "readchild(%s, %d, %d) done: amt = %d errno = %d\n",
+	debugmsg(DM_MISC, "readchild(%s, %d, %d) done: amt = %lld errno = %d\n",
 		 child->c_name, child->c_pid, child->c_readfd, amt, errno);
 
 	/*
