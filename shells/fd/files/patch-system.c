Taken from: [FDclone-users:00145]

diff -u ../old/FD-2.03a/system.c ./system.c
--- ../old/FD-2.03a/system.c	Tue Apr 15 00:00:00 2003
+++ ./system.c	Tue Apr 22 00:00:00 2003
@@ -3926,7 +3926,11 @@
 	char *tmp;
 	int type;
 
-	if (rp -> next && (errp = doredirect(rp -> next))) return(errp);
+	rp -> type &= ~MD_REST;
+	if (rp -> next) {
+		if ((errp = doredirect(rp -> next))) return(errp);
+		if (((rp -> next) -> type) & MD_REST) rp -> type |= MD_REST;
+	}
 
 	type = rp -> type;
 	if (!(rp -> filename)) tmp = NULL;
@@ -3940,6 +3944,25 @@
 		tmp = NULL;
 		type &= ~MD_FILEDESC;
 	}
+#ifdef	FD
+	else {
+		char **argv;
+		int n, argc;
+
+		argv = (char **)malloc2(2 * sizeof(char *));
+		argv[0] = tmp;
+		argv[1] = NULL;
+		argc = 1;
+		n = replaceargs(&argc, &argv, NULL, 0);
+		tmp = argv[0];
+		free(argv);
+		if (n < 0) {
+			free(tmp);
+			return(rp);
+		}
+		if (n) rp -> type |= MD_REST;
+	}
+#endif	/* FD */
 
 	if (!tmp);
 	else if (type & MD_HEREDOC) {
@@ -7230,7 +7253,6 @@
 		}
 		else for (i = 0; i < argc; i++) stripquote(argv[i], 1);
 #ifdef	FD
-		replaceargs(NULL, NULL, NULL, 0);
 		if (replaceargs(&argc, &argv, NULL, -1) < 0) {
 			freevar(argv);
 			return(-1);
@@ -9558,9 +9580,6 @@
 		fflush(stderr);
 	}
 
-#ifdef	FD
-	replaceargs(NULL, NULL, NULL, 0);
-#endif
 	for (;;) {
 #ifdef	FD
 		char **dupargv;
@@ -9806,6 +9825,10 @@
 		return(-1);
 #endif
 
+#ifdef	FD
+	replaceargs(NULL, NULL, NULL, 0);
+#endif
+
 	if (!(trp -> comm) || pipein > 0L) {
 #if	!MSDOS && !defined (NOJOB)
 		if (pipein > 0L) stackjob(pipein, 0, trp);
@@ -9822,7 +9845,7 @@
 #endif
 		ret_status = (ret >= 0) ? ret : RET_FAIL;
 	}
-	else {
+	else for (;;) {
 		if (!(errp = doredirect((trp -> comm) -> redp)))
 #if	MSDOS || defined (USEFAKEPIPE)
 			ret = exec_process(trp);
@@ -9854,6 +9877,11 @@
 		}
 		closeredirect((trp -> comm) -> redp);
 		ret_status = (ret >= 0) ? ret : RET_FAIL;
+#ifdef	FD
+		if (!errp && ((trp -> comm) -> redp) -> type & MD_REST)
+			continue;
+#endif
+		break;
 	}
 	trp = tmptr;
 
