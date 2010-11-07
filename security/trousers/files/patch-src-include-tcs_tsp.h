--- src/include/tcs_tsp.h.orig	2010-01-29 01:27:51.000000000 +0900
+++ src/include/tcs_tsp.h	2010-10-24 21:04:04.822560729 +0900
@@ -79,7 +79,13 @@
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
