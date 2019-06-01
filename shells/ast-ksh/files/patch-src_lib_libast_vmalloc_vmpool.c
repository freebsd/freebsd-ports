--- src/lib/libast/vmalloc/vmpool.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/vmalloc/vmpool.c
@@ -47,7 +47,7 @@ typedef struct _vmpool_s
 	Pool_t*		free;	/* list of free blocks	*/
 } Vmpool_t;
 
-#define POOLSIZE(sz)	ROUND(ROUND((sz), sizeof(Pool_t)), ALIGN)
+#define POOLSIZE(sz)	ROUND(ROUND((sz), sizeof(Pool_t)), MEM_ALIGN)
 
 #ifdef DEBUG
 static int	N_pool;	/* counter for Vmpool calls	*/
@@ -206,7 +206,7 @@ static int poolstat(Vmalloc_t* vm, Vmsta
 	if(pool->size <= 0 )
 		return -1;
 
-	size = ROUND(pool->size, ALIGN);
+	size = ROUND(pool->size, MEM_ALIGN);
 
 	for(pl = pool->free; pl; pl = pl->next )
 		st->n_free += 1;
