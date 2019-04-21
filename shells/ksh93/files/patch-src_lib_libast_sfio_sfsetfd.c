--- src/lib/libast/sfio/sfsetfd.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/sfio/sfsetfd.c
@@ -108,12 +108,10 @@ int	newfd;
 					SFMTXRETURN(f, -1);
 				}
 
-#if _mmap_worthy
 				if((f->bits&SF_MMAP) && f->data)
 				{	SFMUNMAP(f,f->data,f->endb-f->data);
 					f->data = NIL(uchar*);
 				}
-#endif
 
 				/* make stream appears uninitialized */
 				f->endb = f->endr = f->endw = f->data;
