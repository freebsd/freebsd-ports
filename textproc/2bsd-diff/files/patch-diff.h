--- diff.h.orig	Thu Aug 29 06:44:35 1985
+++ diff.h	Wed Mar 19 01:35:49 2003
@@ -5,10 +5,11 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <sys/param.h>
 #include <sys/stat.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <signal.h>
 
 /*
@@ -61,7 +62,7 @@
  */
 int	status;
 int	anychange;
-char	*tempfile;		/* used when comparing against std input */
+char	tempfile[MAXPATHLEN];	/* used when comparing against std input */
 
 /*
  * Variables for diffdir.
@@ -77,9 +78,9 @@
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
