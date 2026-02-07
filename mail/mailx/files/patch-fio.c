--- fio.c	Tue Jun  4 21:05:13 2002
+++ fio.c	Tue Jun  4 21:05:42 2002
@@ -313,7 +313,7 @@
 	register char *cp, *shell;
 	int pivec[2];
 	struct stat sbuf;
-	extern union wait wait_status;
+	extern int wait_status;
 
 	/*
 	 * The order of evaluation is "%" and "#" expand into constants.
@@ -365,7 +365,7 @@
 	close(pivec[1]);
 	l = read(pivec[0], xname, BUFSIZ);
 	close(pivec[0]);
-	if (wait_child(pid) < 0 && wait_status.w_termsig != SIGPIPE) {
+	if (wait_child(pid) < 0 && WTERMSIG(wait_status) != SIGPIPE) {
 		fprintf(stderr, "\"%s\": Expansion failed.\n", name);
 		return NOSTR;
 	}
