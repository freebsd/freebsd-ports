--- prf_common_circular.c.orig	2019-05-10 21:23:56 UTC
+++ prf_common_circular.c
@@ -318,8 +318,14 @@ static int show_malloc_stats(char * mesg)
 
    if( show_stats ) {
       fprintf(stderr,"\n----- malloc stats: %s\n", mesg);
-#ifndef DARWIN
+#if defined(__linux__)
       malloc_stats();
+#elif defined(__FreeBSD__)
+      #include <stdlib.h>
+      #include <malloc_np.h>
+      malloc_stats_print(NULL, NULL, "g");
+#else
+      fprintf(stderr, "No malloc_stats() on this platform.\n");
 #endif
    }
 
