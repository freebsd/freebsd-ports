--- src/lib/libast/sfio/sfmode.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/sfio/sfmode.c
@@ -404,7 +404,6 @@ reg int		local;	/* a local call */
 
 	if(f->mode&SF_GETR)
 	{	f->mode &= ~SF_GETR;
-#if _mmap_worthy
 		if(f->bits&SF_MMAP)
 		{
 			if (!++f->ngetr)
@@ -415,7 +414,6 @@ reg int		local;	/* a local call */
 				f->ngetr = f->tiny[0] = 0;
 			}
 		}
-#endif
 		if(f->getr)
 		{	f->next[-1] = f->getr;
 			f->getr = 0;
@@ -519,12 +517,10 @@ reg int		local;	/* a local call */
 			if((f->flags&(SF_SHARE|SF_PUBLIC)) == (SF_SHARE|SF_PUBLIC) &&
 			   (addr = SFSK(f,0,SEEK_CUR,f->disc)) != f->here)
 			{
-#if _mmap_worthy
 				if((f->bits&SF_MMAP) && f->data)
 				{	SFMUNMAP(f,f->data,f->endb-f->data);
 					f->data = NIL(uchar*);
 				}
-#endif
 				f->endb = f->endr = f->endw = f->next = f->data;
 				f->here = addr;
 			}
@@ -567,13 +563,11 @@ reg int		local;	/* a local call */
 		}
 
 		f->mode = SF_WRITE|SF_LOCK;
-#if _mmap_worthy
 		if(f->bits&SF_MMAP)
 		{	if(f->data)
 				SFMUNMAP(f,f->data,f->endb-f->data);
 			(void)SFSETBUF(f,(Void_t*)f->tiny,(size_t)SF_UNBOUND);
 		}
-#endif
 		if(f->data == f->tiny)
 		{	f->endb = f->data = f->next = NIL(uchar*);
 			f->size = 0;
