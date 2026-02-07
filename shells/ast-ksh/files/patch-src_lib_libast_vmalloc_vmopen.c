--- src/lib/libast/vmalloc/vmopen.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/vmalloc/vmopen.c
@@ -97,10 +97,10 @@ int		mode;	/* type of region		*/
 					write(9, "vmalloc: panic: heap initialization error #2\n", 45);
 				return NIL(Vmalloc_t*);
 			}
-			/**/DEBUG_ASSERT(VMLONG(vd)%ALIGN == 0);
+			/**/DEBUG_ASSERT(VMLONG(vd)%MEM_ALIGN == 0);
 
 			if(vd->mode & VM_MEMORYF) /* point addr to Vmalloc_t */
-				addr -= ROUND(sizeof(Vmalloc_t), ALIGN);
+				addr -= ROUND(sizeof(Vmalloc_t), MEM_ALIGN);
 		}
 	}
 
@@ -110,7 +110,7 @@ int		mode;	/* type of region		*/
 		incr = disc->round <= 0 ? _Vmpagesize : ROUND(disc->round, _Vmpagesize);
 
 		/* size of Vmalloc_t if embedded in the same initial segment */
-		vmsz = (mode&VM_MEMORYF) ? ROUND(sizeof(Vmalloc_t),ALIGN) : 0;
+		vmsz = (mode&VM_MEMORYF) ? ROUND(sizeof(Vmalloc_t),MEM_ALIGN) : 0;
 
 		vdsz = 0; /* get actual size of Vmdata_t including method specific data */
 		if(!meth->eventf || (*meth->eventf)(vmp, VM_OPEN, &vdsz) < 0 || vdsz <= 0 )
@@ -118,13 +118,13 @@ int		mode;	/* type of region		*/
 				write(9, "vmalloc: panic: heap initialization error #3\n", 45);
 			return NIL(Vmalloc_t*);
 		}
-		vdsz = ROUND(vdsz, ALIGN);
+		vdsz = ROUND(vdsz, MEM_ALIGN);
 
-		sgsz = ROUND(sizeof(Seg_t), ALIGN); /* size of segment structure */
+		sgsz = ROUND(sizeof(Seg_t), MEM_ALIGN); /* size of segment structure */
 
 		/* get initial memory segment containing Vmdata_t, Seg_t and some extra */
 		size = vmsz + vdsz + sgsz + 8*_Vmpagesize;
-		size = ROUND(size,incr); /**/DEBUG_ASSERT(size%ALIGN == 0 );
+		size = ROUND(size,incr); /**/DEBUG_ASSERT(size%MEM_ALIGN == 0 );
 		if(!(base = (Vmuchar_t*)(*disc->memoryf)(vmp, NIL(Void_t*), 0, size, disc)) )
 		{	if(initheap)
 				write(9, "vmalloc: panic: heap initialization error #4\n", 45);
@@ -136,14 +136,14 @@ int		mode;	/* type of region		*/
 			memset(base, 0, vmsz + vdsz + sgsz);
 
 		/* make sure memory is properly aligned */
-		if((algn = (ssize_t)(VMLONG(base)%ALIGN)) == 0 )
+		if((algn = (ssize_t)(VMLONG(base)%MEM_ALIGN)) == 0 )
 			addr = base;
-		else	addr = base + (ALIGN-algn);
-		/**/DEBUG_ASSERT(VMLONG(addr)%ALIGN == 0 );
+		else	addr = base + (MEM_ALIGN-algn);
+		/**/DEBUG_ASSERT(VMLONG(addr)%MEM_ALIGN == 0 );
 
 		/* addresses of Vmdata_t and root segment */
-		vd = (Vmdata_t*)(addr + vmsz); /**/DEBUG_ASSERT(VMLONG(vd)%ALIGN == 0);
-		seg = (Seg_t*)(addr + vmsz + vdsz); /**/DEBUG_ASSERT(VMLONG(seg)%ALIGN == 0);
+		vd = (Vmdata_t*)(addr + vmsz); /**/DEBUG_ASSERT(VMLONG(vd)%MEM_ALIGN == 0);
+		seg = (Seg_t*)(addr + vmsz + vdsz); /**/DEBUG_ASSERT(VMLONG(seg)%MEM_ALIGN == 0);
 
 		/* set Vmdata_t data */
 		vd->mode = mode;
