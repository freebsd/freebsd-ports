--- src/mem/halloc.c.orig	2016-10-31 10:10:30 UTC
+++ src/mem/halloc.c
@@ -34,7 +34,7 @@ typedef struct hblock
 #endif
 	hlist_item_t  siblings; /* 2 pointers */
 	hlist_head_t  children; /* 1 pointer  */
-	max_align_t   data[1];  /* not allocated, see below */
+	h_max_align_t   data[1];  /* not allocated, see below */
 	
 } hblock_t;
 
