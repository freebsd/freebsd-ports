--- metamail/shared.c.orig	Sun May 16 20:19:32 1993
+++ metamail/shared.c	Mon Dec 18 11:46:22 2006
@@ -1,4 +1,6 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 #include <config.h>
 #ifdef SYSV
@@ -6,7 +8,6 @@
 #include <sys/utsname.h>
 #endif
 
-extern char *malloc();
 char **Exceptions;
 int *NeedsPortableNewlines;
 int ExceptionsAlloced = 0, ExceptionsUsed = 0;
