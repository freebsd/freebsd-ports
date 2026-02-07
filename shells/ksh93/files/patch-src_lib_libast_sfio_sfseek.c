--- src/lib/libast/sfio/sfseek.c.orig	2020-02-08 10:39:38.000000000 -0800
+++ src/lib/libast/sfio/sfseek.c	2020-02-09 20:01:11.420655000 -0800
@@ -204,18 +204,9 @@
 #ifdef MAP_TYPE
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
+		newpos(f,p);
+		if(!hardseek)
+			goto done;
 	}
 #endif
 
