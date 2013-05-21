Eliminate unused variables.
--- src/parse.c	2009-11-24 07:13:28.000000000 -0500
+++ src/parse.c	2013-02-12 16:12:57.000000000 -0500
@@ -8,9 +8,7 @@
 {
 	FILE *f;
-	unsigned int line_number, i;
 	char line[BUFSIZ];
 	int leftside;
 	char key[BUFSIZ], value[BUFSIZ];
-	char *arg, *cmt, *opt;
 	char *p;
 	struct stat defshell_stat;
@@ -18,5 +16,5 @@
 	char *shell;
 	int found = FALSE;
-	unsigned int x=0, y=0;
+	unsigned int x=0;
 
 //	bzero(c, sizeof (struct s_option));
