--- diff.c.orig	Wed Nov 13 05:31:26 1991
+++ diff.c	Wed Mar 19 01:31:23 2003
@@ -176,9 +176,10 @@
 	return (a > b ? a : b);
 }
 
+sig_t
 done()
 {
-	if (tempfile)
+	if (tempfile[0])
 		unlink(tempfile);
 	exit(status);
 }
@@ -198,7 +199,6 @@
 char *p;
 {
 	register char *q;
-	char *realloc();
 
 	if ((q = realloc(p, (unsigned)n)) == NULL)
 		noroom();
