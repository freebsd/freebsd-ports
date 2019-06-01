--- src/lib/libast/sfio/sfpurge.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/sfio/sfpurge.c
@@ -54,7 +54,6 @@ Sfio_t*	f;
 	SFLOCK(f,0);
 
 	/* if memory map must be a read stream, pretend data is gone */
-#if _mmap_worthy
 	if(f->bits&SF_MMAP)
 	{	f->here -= f->endb - f->next;
 		if(f->data)
@@ -64,7 +63,6 @@ Sfio_t*	f;
 		SFOPEN(f,0);
 		SFMTXRETURN(f, 0);
 	}
-#endif
 
 	switch(f->mode&~SF_LOCK)
 	{
