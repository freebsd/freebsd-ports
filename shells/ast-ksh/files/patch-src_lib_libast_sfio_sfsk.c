--- src/lib/libast/sfio/sfsk.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/sfio/sfsk.c
@@ -49,12 +49,10 @@ Sfdisc_t*	disc;
 			SFMTXRETURN(f, (Sfoff_t)(-1));
 		if(SFSYNC(f) < 0)
 			SFMTXRETURN(f, (Sfoff_t)(-1));
-#if _mmap_worthy
 		if(f->mode == SF_READ && (f->bits&SF_MMAP) && f->data)
 		{	SFMUNMAP(f, f->data, f->endb-f->data);
 			f->data = NIL(uchar*);
 		}
-#endif
 		f->next = f->endb = f->endr = f->endw = f->data;
 	}
 
