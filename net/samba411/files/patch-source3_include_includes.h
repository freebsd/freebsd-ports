--- source3/include/includes.h.orig	2019-01-15 10:07:00 UTC
+++ source3/include/includes.h
@@ -322,6 +322,8 @@ typedef char fstring[FSTRING_LEN];
  * the *bottom* of include files so as not to conflict. */
 #ifdef ENABLE_DMALLOC
 #  include <dmalloc.h>
+#elif ENABLE_JEMALLOC
+#  include <jemalloc/jemalloc.h>
 #endif
 
 
