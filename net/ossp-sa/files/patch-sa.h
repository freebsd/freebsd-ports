--- sa.h.orig	Tue Apr 13 20:44:58 2004
+++ sa.h	Tue Apr 13 20:45:30 2004
@@ -41,10 +41,6 @@
 #include "config.h"
 #endif
 
-/* fallback for POSIX socklen_t */
-#if defined(HAVE_CONFIG_H) && !defined(HAVE_SOCKLEN_T)
-typedef int socklen_t;
-#endif
 
 /* embedding support */
 #ifdef SA_PREFIX
