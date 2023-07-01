--- mng.c.orig	2004-09-01 03:50:32 UTC
+++ mng.c
@@ -48,13 +48,13 @@ void mng_window_setup __P((mngstuff *mymng, int x, int
 /* callbacks for the mng decoder */
 
 /* memory allocation; data must be zeroed */
-mng_ptr mymngalloc(mng_uint32 size)
+mng_ptr mymngalloc(mng_size_t size)
 {
 	return (mng_ptr)calloc(1, size);
 }
 
 /* memory deallocation */
-void mymngfree(mng_ptr p, mng_uint32 size)
+void mymngfree(mng_ptr p, mng_size_t size)
 {
 	free(p);
 	return;
