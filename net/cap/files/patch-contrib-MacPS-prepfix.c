--- contrib/MacPS/prepfix.c.orig	Thu Feb 28 13:45:17 1991
+++ contrib/MacPS/prepfix.c	Sat Mar 20 14:56:52 2004
@@ -60,7 +60,7 @@
 {
 	register STR *str;
 	register FILE *tp;
-	register int i;
+	register int i, tmpfd;
 	register unsigned char *lp;
 	char buf[BUFSIZ];
 	char *malloc(), *realloc();
@@ -109,8 +109,7 @@
 		fprintf(stderr, "%s: Can't open %s\n", myname, *argv);
 		exit(1);
 	}
-	mktemp(tempname);
-	if((tp = fopen(tempname, "w+")) == NULL) {
+	if ( ((tmpfd = mkstemp(tempname)) == -1 ) || (tp = fdopen(tmpfd, "w+")) ) == NULL) {
 		fprintf(stderr, "%s: Can't create temp file %s\n",
 		 myname, tempname);
 		exit(1);
