--- src/bitset.c.old	Thu Feb 26 15:21:52 2004
+++ src/bitset.c	Thu Feb 26 15:22:14 2004
@@ -1,8 +1,6 @@
 #include "config.h"
 
-#if HAVE_MALLOC_H
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 #include <assert.h>
 #include <stdio.h>
 #include "bitset.h"
