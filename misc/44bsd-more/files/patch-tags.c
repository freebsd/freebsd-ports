diff -U8 -r ../work.orig/tags.c ./tags.c
--- ../work.orig/tags.c	Fri Jan  5 22:17:02 2001
+++ ./tags.c	Fri Jan  5 22:36:53 2001
@@ -37,17 +37,17 @@
 #endif /* not lint */
 
 #ifndef lint
 static const char rcsid[] =
   "$FreeBSD$";
 #endif /* not lint */
 
 #include <sys/types.h>
-#include <sys/queue.h>
+#include "queue.h"
 
 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 #include "less.h"
