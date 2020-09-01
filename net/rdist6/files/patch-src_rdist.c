--- src/rdist.c.orig	1998-11-10 04:13:50 UTC
+++ src/rdist.c
@@ -62,8 +62,8 @@ static char copyright[] =
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
@@ -107,12 +107,13 @@ main(argc, argv, envp)
 	register char *cp;
 	int cmdargs = 0;
 	int c;
+	const char *errstr;
 
 	/*
 	 * We initialize progname here instead of init() because
 	 * things in msgparseopts() need progname set.
 	 */
-	setprogname(argv);
+	progname = basename(argv[0]);
 
 	if (cp = msgparseopts(localmsglist, TRUE)) {
 		error("Bad builtin log option (%s): %s.", 
@@ -176,10 +177,20 @@ main(argc, argv, envp)
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
