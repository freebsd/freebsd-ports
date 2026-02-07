--- src/lib/libast/vmalloc/vmsegment.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/vmalloc/vmsegment.c
@@ -194,7 +194,7 @@ static Block_t* _vmseginit(Vmdata_t* vmd
 
 	/* available memory in Seg_t for allocation usage */
 	size = (base+size) - SEGDATA(seg);
-	size = (size/ALIGN)*ALIGN; /* must be multiple of ALIGN's */
+	size = (size/MEM_ALIGN)*MEM_ALIGN; /* must be multiple of MEM_ALIGN's */
 
 	/* block at start of memory */
 	seg->begb = (Block_t*)SEGDATA(seg);
@@ -256,7 +256,7 @@ static Block_t* _vmsegalloc(Vmalloc_t* v
 	static size_t	Segunit = 0;
 	/**/DEBUG_COUNT(N_segalloc);
 	/**/DEBUG_ASSERT(!blk || (isblock(vmdt, blk) && (SIZE(blk)&BUSY) ) );
-	/**/DEBUG_ASSERT(_Vmpagesize > 0 && _Vmpagesize%ALIGN == 0 );
+	/**/DEBUG_ASSERT(_Vmpagesize > 0 && _Vmpagesize%MEM_ALIGN == 0 );
 
 /* transition to a fixed place to unlock before returning */
 #undef	RETURN
@@ -381,9 +381,9 @@ static Block_t* _vmsegalloc(Vmalloc_t* v
 		}
 
 		/* segment must start at an aligned address */
-		if((sz = (size_t)(VMLONG(base)%ALIGN)) == 0)
+		if((sz = (size_t)(VMLONG(base)%MEM_ALIGN)) == 0)
 			seg = (Seg_t*)base;
-		else	seg = (Seg_t*)(base + ALIGN-sz);
+		else	seg = (Seg_t*)(base + MEM_ALIGN-sz);
 		blk = _vmseginit(vmdt, seg, base, segsz, 0);
 	}
 
