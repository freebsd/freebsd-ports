--- src/rdist.c.orig	2001-10-22 13:29:22.000000000 -0700
+++ src/rdist.c	2024-03-19 17:15:49.254435000 -0700
@@ -88,8 +88,8 @@
 char   	       *distfile = NULL;		/* Name of distfile to use */
 int     	maxchildren = MAXCHILDREN;	/* Max no of concurrent PIDs */
 int		nflag = 0;			/* Say without doing */
-long		min_freespace = 0;		/* Min filesys free space */
-long		min_freefiles = 0;		/* Min filesys free # files */
+int64_t		min_freespace = 0;		/* Min filesys free space */
+int64_t		min_freefiles = 0;		/* Min filesys free # files */
 FILE   	       *fin = NULL;			/* Input file pointer */
 char		localmsglist[] = "stdout=all:notify=all:syslog=nerror,ferror";
 char   	       *remotemsglist = NULL;
@@ -132,13 +132,13 @@
 	register char *cp;
 	int cmdargs = 0;
 	int c;
-	char *getenv();
+	const char *errstr;
 
 	/*
 	 * We initialize progname here instead of init() because
 	 * things in msgparseopts() need progname set.
 	 */
-	setprogname(argv);
+	progname = basename(argv[0]);
 
 	if (cp = msgparseopts(localmsglist, TRUE)) {
 		error("Bad builtin log option (%s): %s.", 
@@ -209,10 +209,20 @@
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
