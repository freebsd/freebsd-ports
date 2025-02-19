--- alloc.c.orig	2025-02-18 15:59:35.263097000 -0800
+++ alloc.c	2025-02-18 16:02:58.402654000 -0800
@@ -55,61 +55,6 @@
 char   *memtop = NULL;		/* PWP: top of current memory */
 char   *membot = NULL;		/* PWP: bottom of allocatable memory */
 
-ptr_t
-Malloc(n)
-    size_t  n;
-{
-    ptr_t   ptr;
-
-    if (membot == NULL)
-	memtop = membot = sbrk(0);
-    if ((ptr = malloc(n)) == (ptr_t) 0) {
-	child++;
-	stderror(ERR_NOMEM);
-    }
-    return (ptr);
-}
-
-ptr_t
-Realloc(p, n)
-    ptr_t   p;
-    size_t  n;
-{
-    ptr_t   ptr;
-
-    if (membot == NULL)
-	memtop = membot = sbrk(0);
-    if ((ptr = realloc(p, n)) == (ptr_t) 0) {
-	child++;
-	stderror(ERR_NOMEM);
-    }
-    return (ptr);
-}
-
-ptr_t
-Calloc(s, n)
-    size_t  s, n;
-{
-    ptr_t   ptr;
-
-    if (membot == NULL)
-	memtop = membot = sbrk(0);
-    if ((ptr = calloc(s, n)) == (ptr_t) 0) {
-	child++;
-	stderror(ERR_NOMEM);
-    }
-
-    return (ptr);
-}
-
-void
-Free(p)
-    ptr_t   p;
-{
-    if (p)
-	free(p);
-}
-
 /*
  * mstats - print out statistics about malloc
  *
