--- src/include/tcs_tsp.h.orig	2014-04-24 18:05:44 UTC
+++ src/include/tcs_tsp.h
@@ -79,7 +79,13 @@ struct key_disk_cache
 /* XXX Get rid of this, there's no reason to set an arbitrary limit */
 #define MAX_KEY_CHILDREN	10
 
+#ifndef STRUCTURE_PACKING_ATTRIBUTE
+#ifdef __GCC
 #define STRUCTURE_PACKING_ATTRIBUTE	__attribute__((packed))
+#else
+#define STRUCTURE_PACKING_ATTRIBUTE    /* */
+#endif
+#endif
 
 #ifdef TSS_DEBUG
 #define DBG_ASSERT(x)	assert(x)
