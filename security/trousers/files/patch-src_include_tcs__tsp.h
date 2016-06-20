--- src/include/tcs_tsp.h.orig	2016-06-20 15:21:26 UTC
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
