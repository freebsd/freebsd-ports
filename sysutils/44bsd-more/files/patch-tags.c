--- tags.c.orig	Fri Jan 12 15:52:49 2001
+++ tags.c	Fri Jan 12 15:55:10 2001
@@ -42,7 +42,7 @@
 #endif /* not lint */
 
 #include <sys/types.h>
-#include <sys/queue.h>
+#include "queue.h"
 
 #include <ctype.h>
 #include <stdio.h>
