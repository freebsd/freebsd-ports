--- supcmeat.c.orig	Fri Oct 25 10:27:43 2002
+++ supcmeat.c	Fri Oct 25 10:27:43 2002
@@ -1107,7 +1107,7 @@
 {
 	struct stat sbuf;
 	struct timeval tbuf[2];
-	union wait w;
+	int w;
 
 	if (thisC->Cflags&CFLIST) {
 		vnotify ("SUP Would execute %s\n",t->Tname);
@@ -1123,18 +1123,18 @@
 		notify ("SUP Unable to stat file %s\n", *name);
 		sbuf.st_ino = 0;
 	}
-	w.w_status = system (t->Tname);
-	if (WIFEXITED(w) && w.w_retcode != 0) {
+	w = system (t->Tname);
+	if (WIFEXITED(w) && WEXITSTATUS(w) != 0) {
 		notify ("SUP: Execute command returned failure status %#o\n",
-			w.w_retcode);
+			WEXITSTATUS(w));
 		thisC->Cnogood = TRUE;
 	} else if (WIFSIGNALED(w)) {
 		notify ("SUP: Execute command killed by signal %d\n",
-			w.w_termsig);
+			WTERMSIG(w));
 		thisC->Cnogood = TRUE;
 	} else if (WIFSTOPPED(w)) {
 		notify ("SUP: Execute command stopped by signal %d\n",
-			w.w_stopsig);
+			WSTOPSIG(w));
 		thisC->Cnogood = TRUE;
 	}
 	if ((sbuf.st_ino != 0) && (sbuf.st_mode&S_IFMT) != S_IFLNK){
