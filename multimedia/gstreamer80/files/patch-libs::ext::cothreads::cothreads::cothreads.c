--- libs/ext/cothreads/cothreads/cothreads.c.orig	Sat Feb  1 16:09:23 2003
+++ libs/ext/cothreads/cothreads/cothreads.c	Mon Mar 17 13:33:43 2003
@@ -22,6 +22,7 @@
 
 #include "pth_p.h" /* this pulls in everything */
 #include <sys/mman.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <stdlib.h>
 
@@ -422,7 +423,7 @@
   *stack = malloc (_cothreads_chunk_size * (1.0 + 1.0/_cothreads_count));
   if (!stack)
     return FALSE;
-  *stack = (void*)((int)*stack &~ (int)(_cothreads_chunk_size / _cothreads_count - 1));
+  *stack = (void*)((intptr_t)*stack &~ (intptr_t)(_cothreads_chunk_size / _cothreads_count - 1));
   *stack += 1;
 #endif
 
