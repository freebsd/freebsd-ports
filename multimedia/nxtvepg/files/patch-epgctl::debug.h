--- epgctl/debug.h.orig	Tue Sep 17 17:23:00 2002
+++ epgctl/debug.h	Sun Jan  5 23:11:30 2003
@@ -207,7 +207,7 @@
 #define xmalloc(SIZE)  chk_malloc((SIZE),__FILE__,__LINE__)
 #define xfree(PTR)     chk_free(PTR)
 #else
-#include <malloc.h>
+#include <stdlib.h>
 void * xmalloc( size_t size );
 #define xfree(PTR)     free(PTR)
 #endif
