--- src/lib/libast/sfio/sfsize.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/sfio/sfsize.c
@@ -80,12 +80,10 @@ Sfio_t*	f;
 
 	if(f->here != s && (f->mode&SF_READ) )
 	{	/* buffered data is known to be invalid */
-#if _mmap_worthy
 		if((f->bits&SF_MMAP) && f->data)
 		{	SFMUNMAP(f,f->data,f->endb-f->data);
 			f->data = NIL(uchar*);
 		}
-#endif
 		f->next = f->endb = f->endr = f->endw = f->data;
 	}
 
