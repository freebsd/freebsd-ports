--- source3/include/includes.h.orig	2018-04-03 05:23:35 UTC
+++ source3/include/includes.h
@@ -323,6 +323,8 @@ typedef char fstring[FSTRING_LEN];
  * the *bottom* of include files so as not to conflict. */
 #ifdef ENABLE_DMALLOC
 #  include <dmalloc.h>
+#elif ENABLE_JEMALLOC
+#  include <jemalloc/jemalloc.h>
 #endif
 
 
