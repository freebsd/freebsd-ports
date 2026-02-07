--- src/lib/libast/sfio/sfrd.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/sfio/sfrd.c
@@ -92,12 +92,10 @@ Sfdisc_t*	disc;
 			{	f->endb = f->next = f->endr = f->data;
 				f->mode &= ~SF_SYNCED;
 			}
-#if _mmap_worthy
 			if((f->bits&SF_MMAP) && f->data)
 			{	SFMUNMAP(f, f->data, f->endb-f->data);
 				f->data = NIL(uchar*);
 			}
-#endif
 			f->next = f->endb = f->endr = f->endw = f->data;
 		}
 	}
@@ -132,7 +130,6 @@ Sfdisc_t*	disc;
 			}
 		}
 
-#if _mmap_worthy
 		if(f->bits&SF_MMAP)
 		{	reg ssize_t	a, round;
 			sfstat_t	st;
@@ -230,7 +227,6 @@ Sfdisc_t*	disc;
 				}
 			}
 		}
-#endif
 
 		/* sync unseekable write streams to prevent deadlock */
 		if(!dosync && f->extent < 0)
