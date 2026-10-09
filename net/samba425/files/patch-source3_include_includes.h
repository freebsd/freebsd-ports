--- source3/include/includes.h.orig	2026-01-20 15:42:54 UTC
+++ source3/include/includes.h
@@ -307,8 +307,9 @@ enum timestamp_set_resolution {
  * the *bottom* of include files so as not to conflict. */
 #ifdef ENABLE_DMALLOC
 #  include <dmalloc.h>
+#elif defined(ENABLE_JEMALLOC) && !defined(__FreeBSD__)
+#  include <jemalloc/jemalloc.h>
 #endif
-
 
 #define MAX_SEC_CTX_DEPTH 8    /* Maximum number of security contexts */
 
