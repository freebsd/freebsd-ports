--- dsh/dsh.c.orig	Tue Jul  6 12:49:37 2004
+++ dsh/dsh.c	Tue Jul  6 12:53:51 2004
@@ -35,6 +35,7 @@
 #include <sys/types.h>
 #include <sys/resource.h>
 #include <sys/wait.h>
+#include <sys/param.h>
 
 #include <errno.h>
 #include <fcntl.h>
@@ -76,6 +77,11 @@
 {
 	extern char	*optarg;
 	extern int	optind;
+#if __FreeBSD_version < 500000
+	extern char	*malloc_options;
+#else
+	extern const char	*_malloc_options;
+#endif
 
 	int someflag, ch, i, fanout, showflag, fanflag;
 	char *p, *q, *group, *nodename, *username;
@@ -93,6 +99,11 @@
 	nodeptr = NULL;
 	nodelink = NULL;
 
+#if __FreeBSD_version < 500000
+	malloc_options = "Z";
+#else
+	_malloc_options = "Z";
+#endif
 	rungroup = malloc(sizeof(char **) * GROUP_MALLOC);
 	if (rungroup == NULL)
 		bailout(__LINE__);
