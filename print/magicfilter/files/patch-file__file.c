diff -ur file/file.c file/file.c
--- file/file.c	Sun Dec  5 01:32:50 2004
+++ file/file.c	Sun Dec  5 01:34:31 2004
@@ -33,7 +33,7 @@
 #include <string.h>
 #include <errno.h>
 #include <sys/param.h>	/* for MAXPATHLEN */
-#include <malloc.h>
+#include <stdlib.h>
 
 extern int getopt();
 extern int optind;
