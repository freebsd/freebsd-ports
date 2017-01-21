--- follow.c.orig	1992-01-17 19:14:42 UTC
+++ follow.c
@@ -3,14 +3,12 @@
    construction.						*/
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include "re.h"
 
-extern char *strncpy(), *strcat(), *strcpy();
-extern int  strlen();
-
 #define TRUE	1
 
-extern char *malloc();
 extern Pset pset_union(); 
 extern int pos_cnt;
 extern Re_node parse();
