--- src/lib/libast/sfio/sfsetbuf.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/sfio/sfsetbuf.c
@@ -302,7 +302,6 @@ size_t	size;	/* buffer size, -1 for defa
 	okmmap = (buf || (f->flags&SF_STRING) || (f->flags&SF_RDWR) == SF_RDWR) ? 0 : 1;
 
 	/* save old buffer info */
-#if _mmap_worthy
 	if(f->bits&SF_MMAP)
 	{	if(f->data)
 		{	if(f->getr && (f->mode&SF_GETR) && f->next)
@@ -311,7 +310,6 @@ size_t	size;	/* buffer size, -1 for defa
 			f->data = NIL(uchar*);
 		}
 	} else
-#endif
 	if(f->data == f->tiny)
 	{	f->data = NIL(uchar*);
 		f->size = 0;
@@ -438,7 +436,6 @@ size_t	size;	/* buffer size, -1 for defa
 		}
 	}
 
-#if _mmap_worthy
 	if(okmmap && size && (f->mode&SF_READ) && f->extent >= 0 )
 	{	/* see if we can try memory mapping */
 		if(!disc)
@@ -457,7 +454,6 @@ size_t	size;	/* buffer size, -1 for defa
 			}
 		}
 	}
-#endif
 
 	/* get buffer space */
 setbuf:
