--- src/lib/lib.h.orig	Wed Jul 31 23:08:06 2002
+++ src/lib/lib.h	Wed Jul 31 23:08:35 2002
@@ -16,7 +16,7 @@
 
 #if HAVE_MALLOC_H
 #   include <malloc.h>
-#elif defined STDC_HEADERS
+#elif defined STDC_HEADERS && !defined __FreeBSD__
     extern void free PARAMS ((char *));
     extern char *malloc PARAMS ((int));
     extern char *realloc PARAMS ((char*, int));
--- patch-src.lib.lib.h ends here ---
