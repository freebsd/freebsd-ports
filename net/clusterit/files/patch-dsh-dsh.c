--- dsh/dsh.c.orig	Fri Jul  2 12:50:52 2004
+++ dsh/dsh.c	Fri Jul  2 12:51:08 2004
@@ -76,6 +76,7 @@
 {
 	extern char	*optarg;
 	extern int	optind;
+	extern char	*malloc_options;
 
 	int someflag, ch, i, fanout, showflag, fanflag;
 	char *p, *q, *group, *nodename, *username;
@@ -93,6 +94,7 @@
 	nodeptr = NULL;
 	nodelink = NULL;
 
+	malloc_options = "Z";
 	rungroup = malloc(sizeof(char **) * GROUP_MALLOC);
 	if (rungroup == NULL)
 		bailout(__LINE__);
