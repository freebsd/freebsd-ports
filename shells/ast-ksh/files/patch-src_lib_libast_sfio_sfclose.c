--- src/lib/libast/sfio/sfclose.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/sfio/sfclose.c
@@ -104,11 +104,9 @@ Sfio_t*	f;
 
 	if(f->data && (!local || (f->flags&SF_STRING) || (f->bits&SF_MMAP) ) )
 	{	/* free buffer */
-#if _mmap_worthy
 		if(f->bits&SF_MMAP)
 			SFMUNMAP(f,f->data,f->endb-f->data);
 		else
-#endif
 		if(f->flags&SF_MALLOC)
 			data = (Void_t*)f->data;
 
