--- diffreg.c.orig	Tue Jan 11 14:39:33 1994
+++ diffreg.c	Wed Mar 19 01:38:48 2003
@@ -270,12 +270,12 @@
 	char buf[BUFSIZ];
 	register int i, f;
 
-	signal(SIGHUP,done);
-	signal(SIGINT,done);
-	signal(SIGPIPE,done);
-	signal(SIGTERM,done);
-	tempfile = mktemp("/tmp/dXXXXX");
-	f = creat(tempfile,0600);
+	signal(SIGHUP, (sig_t) done);
+	signal(SIGINT, (sig_t) done);
+	signal(SIGPIPE, (sig_t) done);
+	signal(SIGTERM, (sig_t) done);
+	strcpy(tempfile, "/tmp/dXXXXX");
+	f = mkstemp(tempfile);
 	if (f < 0) {
 		fprintf(stderr, "diff: ");
 		perror(tempfile);
