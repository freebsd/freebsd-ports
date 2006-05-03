--- util/smalloc.c.orig	Thu Apr 13 21:02:05 2006
+++ util/smalloc.c	Thu Apr 13 21:02:47 2006
@@ -3,7 +3,7 @@
  * contract DE-AC04-76DP00789 and is copyrighted by Sandia Corporation. */
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 static int nmalloc = 0;		/* number of calls to malloc */
 static int nfree = 0;		/* number of calls to free */
