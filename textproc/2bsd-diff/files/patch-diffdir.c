--- diffdir.c.orig	Wed Nov 13 05:31:29 1991
+++ diffdir.c	Wed Mar 19 01:36:38 2003
@@ -172,7 +172,7 @@
 	char *cp;
 {
 	register struct dir *dp = 0, *ep;
-	register struct direct *rp;
+	register struct dirent *rp;
 	register int nitems, n;
 	DIR *dirp;
 
