--- diff.h.orig	1985-08-28 21:44:35 UTC
+++ diff.h
@@ -5,11 +5,17 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <sys/param.h>
 #include <sys/stat.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <signal.h>
+#include <string.h>
+#include <unistd.h>
+#include <fcntl.h>
+#include <sys/wait.h>
+#include <arpa/inet.h>
 
 /*
  * Output format options
@@ -61,7 +67,7 @@ int	context;		/* lines of context to be printed */
  */
 int	status;
 int	anychange;
-char	*tempfile;		/* used when comparing against std input */
+char	tempfile[MAXPATHLEN];	/* used when comparing against std input */
 
 /*
  * Variables for diffdir.
@@ -77,9 +83,20 @@ char	**diffargv;		/* option list to pass to recursive 
 char	*file1, *file2, *efile1, *efile2;
 struct	stat stb1, stb2;
 
-char	*malloc(), *talloc(), *ralloc();
+char	*talloc(), *ralloc();
 char	*savestr(), *splice(), *splicen();
-char	*mktemp(), *copytemp(), *rindex();
-int	done();
+char	*copytemp();
+sig_t	done();
 
 extern	char diffh[], diff[], pr[];
+
+/* declarations */
+void diffdir(char **argv);
+void diffreg();
+void noroom();
+void setfile(char **fpp, char **epp, char *file);
+int useless(register char *cp);
+int min(int, int);
+int max(int, int);
+void prune();
+int skipline(int);
