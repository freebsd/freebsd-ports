--- mgrep.c.orig	Thu Jun 26 21:03:50 2003
+++ mgrep.c	Thu Jun 26 21:03:53 2003
@@ -1,6 +1,7 @@
 /* Copyright (c) 1991 Sun Wu and Udi Manber.  All Rights Reserved. */
 /* multipattern matcher */
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #define MAXPAT  256
 #define MAXLINE 1024
@@ -85,7 +86,7 @@
 	if(p!=0 && p < p_size) p_size = p;
     }
     if(p_size == 0) {
-	fprintf(stderr, "%s: the pattern file is empty\n");
+	fprintf(stderr, "%s: the pattern file is empty\n", Progname);
 	exit(2);
     }
     if(length > 400 && p_size > 2) LONG = 1;
