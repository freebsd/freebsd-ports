--- csh.h.orig	2025-02-18 15:59:35.265140000 -0800
+++ csh.h	2025-02-18 16:04:08.969313000 -0800
@@ -86,10 +86,10 @@
 #include "char.h"
 #include "errnum.h"
 
-#define xmalloc(i)	Malloc(i)
-#define xrealloc(p, i)	Realloc(p, i)
-#define xcalloc(n, s)	Calloc(n, s)
-#define xfree(p)	Free(p)
+#define xmalloc(i)	malloc(i)
+#define xrealloc(p, i)	realloc(p, i)
+#define xcalloc(n, s)	calloc(n, s)
+#define xfree(p)	free(p)
 
 #include <stdio.h>
 FILE *cshin, *cshout, *csherr;
