--- src/lib/libast/sfio/sfseek.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/sfio/sfseek.c
@@ -34,12 +34,10 @@ Sfio_t*	f;
 Sfoff_t p;
 #endif
 {
-#if _mmap_worthy
 	if((f->bits&SF_MMAP) && f->data)
 	{	SFMUNMAP(f, f->data, f->endb-f->data);
 		f->data = NIL(uchar*);
 	}
-#endif
 	f->next = f->endr = f->endw = f->data;
 	f->endb = (f->mode&SF_WRITE) ? f->data+f->size : f->data;
 	if((f->here = p) < 0)
@@ -201,23 +199,13 @@ int	type;	/* 0: from org, 1: from here, 
 	if((p += type == SEEK_CUR ? s : 0) < 0)
 		goto done;
 
-#if _mmap_worthy
 	if(f->bits&SF_MMAP)
 	{	/* if mmap is not great, stop mmaping if moving around too much */
-#if _mmap_worthy < 2
-		if((f->next - f->data) < ((f->endb - f->data)/4) )
-		{	SFSETBUF(f,(Void_t*)f->tiny,(size_t)SF_UNBOUND);
-			hardseek = 1; /* this forces a hard seek below */
-		}
-		else
-#endif
-		{	/* for mmap, f->here can be virtual except for hardseek */
-			newpos(f,p);
-			if(!hardseek)
-				goto done;
-		}
+		/* for mmap, f->here can be virtual except for hardseek */
+		newpos(f,p);
+		if(!hardseek)
+			goto done;
 	}
-#endif
 
 	if(f->endb > f->next)
 	{	/* reduce wastage in future buffer fillings */
