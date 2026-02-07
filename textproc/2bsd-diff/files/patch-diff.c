--- diff.c.orig	1991-11-12 20:31:26 UTC
+++ diff.c
@@ -11,7 +11,7 @@ char	diff[] = DIFF;
 char	diffh[] = DIFFH;
 char	pr[] = PR;
 
-main(argc, argv)
+int main(argc, argv)
 	int argc;
 	char **argv;
 {
@@ -162,23 +162,24 @@ savestr(cp)
 	return (dp);
 }
 
-min(a,b)
+int min(a,b)
 	int a,b;
 {
 
 	return (a < b ? a : b);
 }
 
-max(a,b)
+int max(a,b)
 	int a,b;
 {
 
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
@@ -191,6 +192,7 @@ talloc(n)
 	if ((p = malloc((unsigned)n)) != NULL)
 		return(p);
 	noroom();
+	return NULL;
 }
 
 char *
@@ -198,14 +200,13 @@ ralloc(p,n)
 char *p;
 {
 	register char *q;
-	char *realloc();
 
 	if ((q = realloc(p, (unsigned)n)) == NULL)
 		noroom();
 	return(q);
 }
 
-noroom()
+void noroom()
 {
 	fprintf(stderr, "diff: files too big, try -h\n");
 	done();
