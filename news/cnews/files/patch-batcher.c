--- batch/batcher.c.orig	1994-11-28 02:14:35.000000000 +0100
+++ batch/batcher.c	2014-02-07 16:48:39.000000000 +0100
@@ -12,6 +12,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <signal.h>
 #include <sys/types.h>
@@ -116,7 +117,7 @@
 		 */
 		if (debug)
 			warning("can't find `%s'", article);
-		return;
+		return 0;
 	}
 
 	if (fstat(artfile, &sbuf) < 0)
@@ -143,4 +144,5 @@
 	}
 
 	(void) close(artfile);
+	return 0;
 }
