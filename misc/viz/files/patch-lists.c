--- lists.c.orig
+++ lists.c
@@ -6,10 +6,6 @@
 
 #include "viz.h"
 
-extern errno;
-
-extern char *malloc();
-
 void
 printlist(level, list)
 int level;
