--- src/lib/libast/vmalloc/vmbest.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/vmalloc/vmbest.c
@@ -64,19 +64,19 @@ void _STUB_vmbest(){}
 #define	PK_ALLOW	128	/* min #packs allowed to be created	*/
 
 /* Small requests are rounded to 0%SM_RNDx */
-#define SM_RND0	(1*ALIGN)	/* round value:  1*ALIGN  ==   16	*/
+#define SM_RND0	(1*MEM_ALIGN)	/* round value:  1*MEM_ALIGN  ==   16	*/
 #define SM_BIT0	4		/* (1<<SM_BIT0) == SM_RND0		*/
 #define SM_CNT0	16	   	/* # caches as rounded by SM_RND0	*/
 #define SM_IDX0	0		/* starting cache index of this group	*/
 #define SM_MAX0	(SM_CNT0*SM_RND0)
 	
-#define SM_RND1	(2*ALIGN)	/* round value:  2*ALIGN  ==   32	*/
+#define SM_RND1	(2*MEM_ALIGN)	/* round value:  2*MEM_ALIGN  ==   32	*/
 #define SM_CNT1	8
 #define SM_BIT1	5
 #define SM_IDX1	(SM_IDX0+SM_CNT0)
 #define SM_MAX1	(SM_MAX0 + SM_CNT1*SM_RND1)
 
-#define SM_RND2	(4*ALIGN)	/* round value:  4*ALIGN  ==   64	*/
+#define SM_RND2	(4*MEM_ALIGN)	/* round value:  4*MEM_ALIGN  ==   64	*/
 #define SM_BIT2	6
 #define SM_CNT2	8
 #define SM_IDX2	(SM_IDX1+SM_CNT1)
@@ -167,7 +167,7 @@ static int chktree(Pack_t* pack, Block_t
 	if(_Vmassert & VM_check_reg)
 	{	if(!node) /* the empty tree is always good */
 			return 0;
-		/**/DEBUG_ASSERT(BDSZ(node) >= BODYSIZE && (BDSZ(node)%ALIGN) == 0 );
+		/**/DEBUG_ASSERT(BDSZ(node) >= BODYSIZE && (BDSZ(node)%MEM_ALIGN) == 0 );
 
 		if(SIZE(node) & (BUSY|PFREE)) /* should be BITS-free */
 			{ /**/DEBUG_MESSAGE("Free block corrupted"); /**/DEBUG_ASSERT(0); return -1; }
@@ -252,7 +252,7 @@ static int bestfree(Vmalloc_t* vm, Void_
 	if((Vmuchar_t*)data < vm->data->segmin || (Vmuchar_t*)data >= vm->data->segmax)
 		return -1;
 
-	blk = BLOCK(data); /**/DEBUG_ASSERT((SIZE(blk)&BUSY) && (BDSZ(blk)%ALIGN) == 0 );
+	blk = BLOCK(data); /**/DEBUG_ASSERT((SIZE(blk)&BUSY) && (BDSZ(blk)%MEM_ALIGN) == 0 );
 	pack = PACK(blk); /**/DEBUG_ASSERT(pack->best == (Vmbest_t*)vm->data);
 	if((sz = SIZE(blk))&SMALL )
 		listp = &pack->small[SMDECODE(sz)].free;
@@ -339,7 +339,7 @@ static Block_t* bestpackextend(Vmalloc_t
 
 	/**/DEBUG_ASSERT(!wild || (PACK(wild) == pack && BDSZ(wild) < size && PACKWILD(pack,wild)) );
 	blkz = BDSZ(pack->pblk); /**/DEBUG_ASSERT(blkz >= _Vmpagesize);
-	size += blkz - (wild ? BDSZ(wild) : 0) + EXTRA(pack); /**/DEBUG_ASSERT(size%ALIGN == 0);
+	size += blkz - (wild ? BDSZ(wild) : 0) + EXTRA(pack); /**/DEBUG_ASSERT(size%MEM_ALIGN == 0);
 	if(_Vmassert & VM_debug) debug_printf(2, "%s:%d: PACK(%p) WILD(%p)=%zd BDSZ(%p)=%zd blkz=%zd size=%zu\n", __FILE__, __LINE__, pack, wild, wild ? BDSZ(wild) : 0, pack->pblk, BDSZ(pack->pblk), blkz, size);
 	if(!(pblk = (*_Vmsegalloc)(vm, pack->pblk, size, segtype)) )
 		pblk = pack->pblk;
@@ -383,7 +383,7 @@ static Block_t* bestpackextract(Pack_t* 
 
 	l = r = &link;
 	if((root = pack->root) ) do /* top-down splay tree search */
-	{	/**/DEBUG_ASSERT((size%ALIGN) == 0 && !(SIZE(root)&(BUSY|PFREE)) );
+	{	/**/DEBUG_ASSERT((size%MEM_ALIGN) == 0 && !(SIZE(root)&(BUSY|PFREE)) );
 		if(size == (sz = BDSZ(root)) )
 			break;
 		if(size < sz)
@@ -508,7 +508,7 @@ static int bestlistreclaim(Vmalloc_t* vm
 			continue;
 
 		/**/DEBUG_ASSERT((SIZE(fp)&(BUSY|MARK)) == (BUSY|MARK) );
-		/**/DEBUG_ASSERT(BDSZ(fp) >= sizeof(Body_t) && BDSZ(fp)%ALIGN == 0);
+		/**/DEBUG_ASSERT(BDSZ(fp) >= sizeof(Body_t) && BDSZ(fp)%MEM_ALIGN == 0);
 		SIZE(fp) &= ~BITS; 
 		t = NEXT(fp);
 		SIZE(t) |= PFREE; /**/DEBUG_ASSERT(SIZE(NEXT(fp))&BUSY);
@@ -563,7 +563,7 @@ static Block_t* bestpackalloc(Vmalloc_t*
 	ssize_t		sz;
 	Block_t		*tp, *np, *pblk;
 	Vmbest_t	*best = (Vmbest_t*)vm->data;
-	/**/DEBUG_ASSERT(size >= sizeof(Body_t) && size%ALIGN == 0);
+	/**/DEBUG_ASSERT(size >= sizeof(Body_t) && size%MEM_ALIGN == 0);
 
 	if((tp = pack->alloc) ) /* fast allocation from recent memory */
 	{	pack->alloc = NIL(Block_t*);
@@ -719,9 +719,9 @@ static Void_t* bestalloc(Vmalloc_t* vm, 
 	asospindecl();
 
 	/**/DEBUG_COUNT(N_alloc);
-	/**/DEBUG_ASSERT((ALIGN%(BITS+1)) == 0 );
-	/**/DEBUG_ASSERT((sizeof(Head_t)%ALIGN) == 0 );
-	/**/DEBUG_ASSERT((sizeof(Body_t)%ALIGN) == 0 );
+	/**/DEBUG_ASSERT((MEM_ALIGN%(BITS+1)) == 0 );
+	/**/DEBUG_ASSERT((sizeof(Head_t)%MEM_ALIGN) == 0 );
+	/**/DEBUG_ASSERT((sizeof(Body_t)%MEM_ALIGN) == 0 );
 	/**/DEBUG_ASSERT(sizeof(Block_t) == (sizeof(Body_t)+sizeof(Head_t)) );
 	/**/DEBUG_ASSERT(chkregion((Vmbest_t*)vm->data, local) >= 0);
 
@@ -902,7 +902,7 @@ static Void_t* bestalign(Vmalloc_t* vm, 
 		return NIL(Void_t*);
 
 	algz = LGROUND(size);
-	algn = (*_Vmlcm)(align,ALIGN);
+	algn = (*_Vmlcm)(align,MEM_ALIGN);
 
 	/* non-Vmbest methods may require extra header space */
 	if(METHOD(best) != VM_MTBEST && vm->meth.eventf)
