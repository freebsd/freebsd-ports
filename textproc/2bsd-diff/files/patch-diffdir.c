--- diffdir.c.orig	1991-11-12 20:31:29 UTC
+++ diffdir.c
@@ -24,7 +24,15 @@ struct	dir *setupdir();
 int	header;
 char	title[2*BUFSIZ], *etitle;
 
-diffdir(argv)
+/* declarations */
+void only(struct dir *, int);
+void compare(register struct dir *);
+void scanpr(register struct dir *, int, char *, char *, char *, char *, char *);
+void calldiff(char *);
+int ascii(int);
+int entcmp(const void *, const void *);
+
+void diffdir(argv)
 	char **argv;
 {
 	register struct dir *d1, *d2;
@@ -112,7 +120,7 @@ diffdir(argv)
 	}
 }
 
-setfile(fpp, epp, file)
+void setfile(fpp, epp, file)
 	char **fpp, **epp;
 	char *file;
 {
@@ -130,7 +138,7 @@ setfile(fpp, epp, file)
 	*epp = cp;
 }
 
-scanpr(dp, test, title, file1, efile1, file2, efile2)
+void scanpr(dp, test, title, file1, efile1, file2, efile2)
 	register struct dir *dp;
 	int test;
 	char *title, *file1, *efile1, *file2, *efile2;
@@ -155,24 +163,23 @@ scanpr(dp, test, title, file1, efile1, file2, efile2)
 	}
 }
 
-only(dp, which)
+void only(dp, which)
 	struct dir *dp;
 	int which;
 {
 	char *file = which == 1 ? file1 : file2;
 	char *efile = which == 1 ? efile1 : efile2;
 
-	printf("Only in %.*s: %s\n", efile - file - 1, file, dp->d_entry);
+	printf("Only in %.*s: %s\n", (int)(efile - file - 1),
+		file, dp->d_entry);
 }
 
-int	entcmp();
-
 struct dir *
 setupdir(cp)
 	char *cp;
 {
 	register struct dir *dp = 0, *ep;
-	register struct direct *rp;
+	register struct dirent *rp;
 	register int nitems, n;
 	DIR *dirp;
 
@@ -196,7 +203,7 @@ setupdir(cp)
 		fprintf(stderr, "diff: ran out of memory\n");
 		done();
 	}
-	while (rp = readdir(dirp)) {
+	while ((rp = readdir(dirp))) {
 		ep = &dp[nitems++];
 		ep->d_reclen = rp->d_reclen;
 		ep->d_namlen = rp->d_namlen;
@@ -225,13 +232,13 @@ setupdir(cp)
 	return (dp);
 }
 
-entcmp(d1, d2)
-	struct dir *d1, *d2;
+int entcmp(d1, d2)
+	const void *d1, *d2;
 {
-	return (strcmp(d1->d_entry, d2->d_entry));
+	return strcmp(((struct dir *)d1)->d_entry, ((struct dir *)d2)->d_entry);
 }
 
-compare(dp)
+void compare(dp)
 	register struct dir *dp;
 {
 	register int i, j;
@@ -323,7 +330,7 @@ closem:
 
 char	*prargs[] = { "pr", "-h", 0, "-f", 0, 0 };
 
-calldiff(wantpr)
+void calldiff(wantpr)
 	char *wantpr;
 {
 	int pid, status, status2, pv[2];
@@ -382,7 +389,7 @@ calldiff(wantpr)
 
 #include <a.out.h>
 
-ascii(f)
+int ascii(f)
 	int f;
 {
 	char buf[BUFSIZ];
@@ -407,7 +414,7 @@ ascii(f)
 /*
  * THIS IS CRUDE.
  */
-useless(cp)
+int useless(cp)
 register char *cp;
 {
 
