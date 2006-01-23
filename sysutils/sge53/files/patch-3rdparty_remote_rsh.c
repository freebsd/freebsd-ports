
$FreeBSD$

--- 3rdparty/remote/rsh.c.orig
+++ 3rdparty/remote/rsh.c
@@ -141,7 +141,7 @@
 	struct passwd *pw;
 	struct servent *sp;
 	long omask = 0;
-	int argoff, asrsh, ch, dflag, nflag, one, rem;
+	int argoff, ch, dflag, nflag, one, rem;
 	pid_t pid = 0;
 	uid_t uid;
 	char *args, *host, *p, *user;
@@ -156,7 +156,7 @@
   sigset_t set;
 #endif
 
-	argoff = asrsh = dflag = nflag = 0;
+	argoff = dflag = nflag = 0;
 	one = 1;
 	host = user = NULL;
 
@@ -167,8 +167,6 @@
 		p = argv[0];
 	if (strcmp(p, "rsh"))
 		host = p;
-	else
-		asrsh = 1;
 
 	/* handle "rsh host flags" */
 	if (!host && argc > 2 && argv[1][0] != '-') {
@@ -241,13 +239,9 @@
 	if (!host && !(host = argv[optind++]))
 		usage();
 
-	/* if no further arguments, must have been called as rlogin. */
-	if (!argv[optind]) {
-		if (asrsh)
-			*argv = "rlogin";
-		execvp("rlogin", argv);
-		fprintf(stderr, "can't exec %s", "rlogin"); 
-	}
+	/* if no further arguments, error. We don't call rlogin! */
+	if (!argv[optind])
+      usage();
 
 	argc -= optind;
 	argv += optind;
