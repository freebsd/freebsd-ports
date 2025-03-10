--- src/mpool/mpool.c.orig	2023-10-21 13:00:24 UTC
+++ src/mpool/mpool.c
@@ -241,6 +241,7 @@ static	void	*alloc_pages(mpool_t *mp_p, const unsigned
   (void)printf("allocating %u pages or %lu bytes\n", page_n, size);
 #endif
   
+#if 0
   if (BIT_IS_SET(mp_p->mp_flags, MPOOL_FLAG_USE_SBRK)) {
     mem = sbrk(size);
     if (mem == (void *)-1) {
@@ -263,7 +264,9 @@ static	void	*alloc_pages(mpool_t *mp_p, const unsigned
       mem = (char *)mem + fill;
     }
   }
-  else {
+  else
+#endif
+  {
     state = MAP_PRIVATE;
 #ifdef MAP_FILE
     state |= MAP_FILE;
@@ -937,12 +940,15 @@ mpool_t	*mpool_open(const unsigned int flags, const un
     }
   }
   
+#if 0
   if (BIT_IS_SET(flags, MPOOL_FLAG_USE_SBRK)) {
     mp.mp_fd = -1;
     mp.mp_addr = NULL;
     mp.mp_top = 0;
   }
-  else {
+  else
+#endif
+  {
     /* open dev-zero for our mmaping */
     mp.mp_fd = open("/dev/zero", O_RDWR, 0);
     if (mp.mp_fd < 0) {
