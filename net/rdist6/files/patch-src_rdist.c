--- src/rdist.c.orig	1998-11-09 20:13:50.000000000 -0800
+++ src/rdist.c	2024-03-19 09:08:42.194504000 -0700
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
@@ -72,6 +72,8 @@
 FILE   	       *opendist();
 char	       *path_rdistd = _PATH_RDISTD;
 char	       *path_remsh = _PATH_REMSH;
+char	       *path_remsh_env;
+#define		RDIST_RSH_ENV	"RDIST_RSH"
 
 /*
  * Add a hostname to the host list
@@ -107,12 +109,13 @@
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
@@ -155,6 +158,17 @@
 		fatalerr("This version of rdist should not be installed setuid.");
 #endif	/* DIRECT_RCMD */
 
+	path_remsh_env = getenv(RDIST_RSH_ENV);
+	if (path_remsh_env) {
+		if (cp = searchpath(path_remsh_env))
+			path_remsh = strdup(cp);
+		else {
+			error("Environment incorrect: No component of path \"%s\" exists.",
+			      path_remsh_env);
+			exit(1);
+		}
+	}
+
 	while ((c = getopt(argc, argv, optchars)) != -1)
 		switch (c) {
 		case 'l':
@@ -176,10 +190,20 @@
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
