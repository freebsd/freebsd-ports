--- src/rshrcmd.c	Mon Nov  9 23:15:07 1998
+++ src/rshrcmd.c	Tue Jan 18 14:53:29 2005
@@ -42,5 +42,4 @@
 {
 	int             cpid;
-	struct hostent  *hp;
 	int             sp[2];
 
@@ -48,11 +47,4 @@
 	if (fd2p != 0)
 		return -1;
-	/* validate remote hostname. */
-	hp = gethostbyname(*ahost);
-	if (hp == 0) {
-		error("%s: unknown host", *ahost);
-		return -1;
-	}
-	/* *ahost = hp->h_name;*/ /* This makes me nervous. */
 
 	/* get a socketpair we'll use for stdin and stdout. */
@@ -72,5 +64,5 @@
 		   sp[0]. */
 		(void) close(sp[0]);
-		if (dup2(sp[1], 0) < 0 || dup2(0,1) < 0 || dup2(0, 2) < 0) {
+		if (dup2(sp[1], 0) < 0 || dup2(0,1) < 0) {
 			error("dup2 failed: %s.", SYSERR);
 			_exit(255);
