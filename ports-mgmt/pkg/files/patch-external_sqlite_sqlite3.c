--- external/sqlite/sqlite3.c.orig	2021-11-12 08:57:25 UTC
+++ external/sqlite/sqlite3.c
@@ -13214,7 +13214,7 @@ struct fts5_api {
 ** autoconf-based build
 */
 #if defined(_HAVE_SQLITE_CONFIG_H) && !defined(SQLITECONFIG_H)
-/* #include "config.h" */
+#include "config.h"
 #define SQLITECONFIG_H 1
 #endif
 
@@ -14449,17 +14449,48 @@ typedef INT16_TYPE LogEst;
 #define LARGEST_INT64  (0xffffffff|(((i64)0x7fffffff)<<32))
 #define SMALLEST_INT64 (((i64)-1) - LARGEST_INT64)
 
+
+#ifdef __CHERI_PURE_CAPABILITY__
+#define REQUIRE_CHERI_ALIGNMENT
+#endif
+#ifdef REQUIRE_CHERI_ALIGNMENT
+# define SQLITE_DEFAULT_ALIGNMENT (sizeof(void*) < 16 ? 16 : sizeof(void*))
+#else
+# define SQLITE_DEFAULT_ALIGNMENT (sizeof(void*) < 8 ? 8 : sizeof(void*))
+#endif
+
 /*
 ** Round up a number to the next larger multiple of 8.  This is used
 ** to force 8-byte alignment on 64-bit architectures.
+**
+** XXXAR: For CHERI, we change these macros to ensure 16-byte alignement since
+** renaming them would cause too many conflicts
 */
-#define ROUND8(x)     (((x)+7)&~7)
+#if __has_builtin(__builtin_align_up)
+# define ROUND(x, a) __builtin_align_up(x, a)
+#else
+# define ROUND(x, a)     (((x)+(a-1))&~(a-1))
+#endif
+/* XXX: not actually 8 for CHERI */
+#define ROUND8(x) ROUND(x, SQLITE_DEFAULT_ALIGNMENT)
 
 /*
 ** Round down to the nearest multiple of 8
 */
-#define ROUNDDOWN8(x) ((x)&~7)
+#if __has_builtin(__builtin_align_down)
+# define ROUNDDOWN(x, a) __builtin_align_down(x, 8)
+#else
+# define ROUNDDOWN(x, a) ((x)&~(a-1))
+#endif
+/* XXX: not actually 8 for CHERI */
+#define ROUNDDOWN8(x) ROUNDDOWN(x, SQLITE_DEFAULT_ALIGNMENT)
 
+#if __has_builtin(__builtin_is_aligned)
+# define ALIGNED_TO(X, A) __builtin_is_aligned(X, A)
+#else
+# define ALIGNED_TO(X, A) ((((char*)(X) - (char*)0)&((A)-1))==0)
+#endif
+
 /*
 ** Assert that the pointer X is aligned to an 8-byte boundary.  This
 ** macro is used only within assert() to verify that the code gets
@@ -14472,7 +14503,12 @@ typedef INT16_TYPE LogEst;
 #ifdef SQLITE_4_BYTE_ALIGNED_MALLOC
 # define EIGHT_BYTE_ALIGNMENT(X)   ((((char*)(X) - (char*)0)&3)==0)
 #else
-# define EIGHT_BYTE_ALIGNMENT(X)   ((((char*)(X) - (char*)0)&7)==0)
+/*
+ * For CHERI support we want 16-byte alignment. We also do this for native to
+ * make debugging easier. The macro name is a lie anyway so I don't see why we
+ * should't lie just a little bit more.
+ */
+# define EIGHT_BYTE_ALIGNMENT(X) ALIGNED_TO(X, SQLITE_DEFAULT_ALIGNMENT)
 #endif
 
 /*
@@ -20868,6 +20904,7 @@ struct sqlite3_value {
     int nZero;          /* Extra zero bytes when MEM_Zero and MEM_Blob set */
     const char *zPType; /* Pointer type when MEM_Term|MEM_Subtype|MEM_Null */
     FuncDef *pDef;      /* Used only when flags==MEM_Agg */
+    _Alignas(SQLITE_DEFAULT_ALIGNMENT) char ensureAlignment;
   } u;
   u16 flags;          /* Some combination of MEM_Null, MEM_Str, MEM_Dyn, etc. */
   u8  enc;            /* SQLITE_UTF8, SQLITE_UTF16BE, SQLITE_UTF16LE */
@@ -23624,6 +23661,8 @@ static malloc_zone_t* _sqliteZone_;
 
 #endif /* __APPLE__ or not __APPLE__ */
 
+_Static_assert(SQLITE_DEFAULT_ALIGNMENT % sizeof(sqlite_int64) == 0, "");
+
 /*
 ** Like malloc(), but remember the size of the allocation
 ** so that we can find it later using sqlite3MemSize().
@@ -23646,8 +23685,9 @@ static void *sqlite3MemMalloc(int nByte){
   sqlite3_int64 *p;
   assert( nByte>0 );
   testcase( ROUND8(nByte)!=nByte );
-  p = SQLITE_MALLOC( nByte+8 );
+  p = SQLITE_MALLOC( nByte+SQLITE_DEFAULT_ALIGNMENT );
   if( p ){
+    p += (SQLITE_DEFAULT_ALIGNMENT/sizeof(sqlite_int64))-1;
     p[0] = nByte;
     p++;
   }else{
@@ -23672,7 +23712,7 @@ static void sqlite3MemFree(void *pPrior){
 #else
   sqlite3_int64 *p = (sqlite3_int64*)pPrior;
   assert( pPrior!=0 );
-  p--;
+  p -= (SQLITE_DEFAULT_ALIGNMENT/sizeof(sqlite_int64));
   SQLITE_FREE(p);
 #endif
 }
@@ -23718,9 +23758,10 @@ static void *sqlite3MemRealloc(void *pPrior, int nByte
   sqlite3_int64 *p = (sqlite3_int64*)pPrior;
   assert( pPrior!=0 && nByte>0 );
   assert( nByte==ROUND8(nByte) ); /* EV: R-46199-30249 */
-  p--;
-  p = SQLITE_REALLOC(p, nByte+8 );
+  p -= (SQLITE_DEFAULT_ALIGNMENT/sizeof(sqlite_int64));
+  p = SQLITE_REALLOC(p, nByte+SQLITE_DEFAULT_ALIGNMENT );
   if( p ){
+    p += (SQLITE_DEFAULT_ALIGNMENT/sizeof(sqlite_int64))-1;
     p[0] = nByte;
     p++;
   }else{
@@ -23843,19 +23884,24 @@ SQLITE_PRIVATE void sqlite3MemSetDefault(void){
 /*
 ** Each memory allocation looks like this:
 **
-**  ------------------------------------------------------------------------
-**  | Title |  backtrace pointers |  MemBlockHdr |  allocation |  EndGuard |
-**  ------------------------------------------------------------------------
+**  --------------------------------------------------------------------------
+**  | Pad | Title | backtrace pointers | MemBlockHdr | allocation | EndGuard |
+**  --------------------------------------------------------------------------
 **
 ** The application code sees only a pointer to the allocation.  We have
 ** to back up from the allocation pointer to find the MemBlockHdr.  The
 ** MemBlockHdr tells us the size of the allocation and the number of
 ** backtrace pointers.  There is also a guard word at the end of the
 ** MemBlockHdr.
+**
+** On CHERI systems we pad the front of the allocation to ensure
+** allocation is sufficently aligned.  We also exclude the EndGuard as it's
+** pointless with bounds.
 */
 struct MemBlockHdr {
   i64 iSize;                          /* Size of this allocation */
   struct MemBlockHdr *pNext, *pPrev;  /* Linked list of all unfreed memory */
+  void *pAllocation;                  /* What malloc allocated */
   char nBacktrace;                    /* Number of backtraces on this alloc */
   char nBacktraceSlots;               /* Available backtrace slots */
   u8 nTitle;                          /* Bytes of title; includes '\0' */
@@ -23956,17 +24002,31 @@ static struct MemBlockHdr *sqlite3MemsysGetHeader(void
   u8 *pU8;
   int nReserve;
 
+#ifndef __CHERI_PURE_CAPABILITY__
   p = (struct MemBlockHdr*)pAllocation;
   p--;
+#else
+  /*
+   * pAllocation's bounds don't contain p so walk the whole list
+   * to find the original.
+   */
+  for ( p = mem->pFirst; p != NULL; p = p->pNext ) {
+    if ( p + 1 == pAllocation )
+      break;
+  }
+  assert( p != NULL )
+#endif
   assert( p->iForeGuard==(int)FOREGUARD );
   nReserve = ROUND8(p->iSize);
   pInt = (int*)pAllocation;
   pU8 = (u8*)pAllocation;
+#ifndef __CHERI_PURE_CAPABILITY__
   assert( pInt[nReserve/sizeof(int)]==(int)REARGUARD );
   /* This checks any of the "extra" bytes allocated due
   ** to rounding up to an 8 byte boundary to ensure 
   ** they haven't been overwritten.
   */
+#endif
   while( nReserve-- > p->iSize ) assert( pU8[nReserve]==0x65 );
   return p;
 }
@@ -24048,16 +24108,29 @@ static void *sqlite3MemMalloc(int nByte){
   void *p = 0;
   int totalSize;
   int nReserve;
+  int nPad = 0;
   sqlite3_mutex_enter(mem.mutex);
   assert( mem.disallow==0 );
   nReserve = ROUND8(nByte);
-  totalSize = nReserve + sizeof(*pHdr) + sizeof(int) +
+#ifdef __CHERI_PURE_CAPABILITY__
+  nReserve = __builtin_cheri_round_representable_length(nReserve);
+#endif
+  totalSize = nReserve + sizeof(*pHdr) +
                mem.nBacktrace*sizeof(void*) + mem.nTitle;
+#ifdef __CHERI_PURE_CAPABILITY__
+  int roundedSize = __builtin_cheri_round_representable_length(totalSize);
+  nPad = roundedSize - totalSize;
+  totalSize = roundedSize;
+#else
+  totalSize += sizeof(int);	/* EndGuard */
+#endif
   p = malloc(totalSize);
   if( p ){
     z = p;
+    z += nPad;
     pBt = (void**)&z[mem.nTitle];
     pHdr = (struct MemBlockHdr*)&pBt[mem.nBacktrace];
+    pHdr->pAllocation = p;
     pHdr->pNext = 0;
     pHdr->pPrev = mem.pLast;
     if( mem.pLast ){
@@ -24087,12 +24160,18 @@ static void *sqlite3MemMalloc(int nByte){
     pHdr->iSize = nByte;
     adjustStats(nByte, +1);
     pInt = (int*)&pHdr[1];
+#ifndef __CHERI_PURE_CAPABILITY__
     pInt[nReserve/sizeof(int)] = REARGUARD;
+#endif
     randomFill((char*)pInt, nByte);
     memset(((char*)pInt)+nByte, 0x65, nReserve-nByte);
     p = (void*)pInt;
   }
   sqlite3_mutex_leave(mem.mutex);
+#ifdef __CHERI_PURE_CAPABILITY__
+  if ( p != NULL )
+    p = __builtin_cheri_bounds_set_exact(p, nReserve);
+#endif
   return p; 
 }
 
@@ -24103,6 +24182,7 @@ static void sqlite3MemFree(void *pPrior){
   struct MemBlockHdr *pHdr;
   void **pBt;
   char *z;
+  void *p;
   assert( sqlite3GlobalConfig.bMemstat || sqlite3GlobalConfig.bCoreMutex==0 
        || mem.mutex!=0 );
   pHdr = sqlite3MemsysGetHeader(pPrior);
@@ -24123,12 +24203,13 @@ static void sqlite3MemFree(void *pPrior){
     assert( mem.pLast==pHdr );
     mem.pLast = pHdr->pPrev;
   }
+  p = pHdr->pAllocation;
   z = (char*)pBt;
   z -= pHdr->nTitle;
   adjustStats((int)pHdr->iSize, -1);
   randomFill(z, sizeof(void*)*pHdr->nBacktraceSlots + sizeof(*pHdr) +
                 (int)pHdr->iSize + sizeof(int) + pHdr->nTitle);
-  free(z);
+  free(p);
   sqlite3_mutex_leave(mem.mutex);  
 }
 
@@ -50446,7 +50527,7 @@ static sqlite3_pcache *pcache1Create(int szPage, int s
   int sz;               /* Bytes of memory required to allocate the new cache */
 
   assert( (szPage & (szPage-1))==0 && szPage>=512 && szPage<=65536 );
-  assert( szExtra < 300 );
+  assert( szExtra < 400 ); // XXX: with CHERI we get szExtra=384 here
 
   sz = sizeof(PCache1) + sizeof(PGroup)*pcache1.separateCache;
   pCache = (PCache1 *)sqlite3MallocZero(sz);
@@ -56270,7 +56351,7 @@ SQLITE_PRIVATE int sqlite3PagerOpen(
   int vfsFlags,            /* flags passed through to sqlite3_vfs.xOpen() */
   void (*xReinit)(DbPage*) /* Function to reinitialize pages */
 ){
-  u8 *pPtr;
+  intptr_t pPtr;
   Pager *pPager = 0;       /* Pager object to allocate and return */
   int rc = SQLITE_OK;      /* Return code */
   int tempFile = 0;        /* True for temp files (incl. in-memory files) */
@@ -56400,7 +56481,7 @@ SQLITE_PRIVATE int sqlite3PagerOpen(
   ** specific formatting and order of the various filenames, so if the format
   ** changes here, be sure to change it there as well.
   */
-  pPtr = (u8 *)sqlite3MallocZero(
+  pPtr = (intptr_t)sqlite3MallocZero(
     ROUND8(sizeof(*pPager)) +            /* Pager structure */
     ROUND8(pcacheSize) +                 /* PCache object */
     ROUND8(pVfs->szOsFile) +             /* The main db file */
@@ -56426,15 +56507,17 @@ SQLITE_PRIVATE int sqlite3PagerOpen(
   pPager->sjfd = (sqlite3_file*)pPtr;     pPtr += journalFileSize;
   pPager->jfd =  (sqlite3_file*)pPtr;     pPtr += journalFileSize;
   assert( EIGHT_BYTE_ALIGNMENT(pPager->jfd) );
-  memcpy(pPtr, &pPager, sizeof(pPager));  pPtr += sizeof(pPager);
+  assert( EIGHT_BYTE_ALIGNMENT(pPtr) );
+  assert( EIGHT_BYTE_ALIGNMENT(pPager) );
+  memcpy((Pager **)pPtr, &pPager, sizeof(pPager));  pPtr += sizeof(pPager);
 
   /* Fill in the Pager.zFilename and pPager.zQueryParam fields */
                                           pPtr += 4;  /* Skip zero prefix */
   pPager->zFilename = (char*)pPtr;
   if( nPathname>0 ){
-    memcpy(pPtr, zPathname, nPathname);   pPtr += nPathname + 1;
+    memcpy((char *)pPtr, zPathname, nPathname);   pPtr += nPathname + 1;
     if( zUri ){
-      memcpy(pPtr, zUri, nUriByte);       pPtr += nUriByte;
+      memcpy((char *)pPtr, zUri, nUriByte);       pPtr += nUriByte;
     }else{
                                           pPtr++;
     }
@@ -56444,8 +56527,8 @@ SQLITE_PRIVATE int sqlite3PagerOpen(
   /* Fill in Pager.zJournal */
   if( nPathname>0 ){
     pPager->zJournal = (char*)pPtr;
-    memcpy(pPtr, zPathname, nPathname);   pPtr += nPathname;
-    memcpy(pPtr, "-journal",8);           pPtr += 8 + 1;
+    memcpy((char *)pPtr, zPathname, nPathname);   pPtr += nPathname;
+    memcpy((char *)pPtr, "-journal",8);           pPtr += 8 + 1;
 #ifdef SQLITE_ENABLE_8_3_NAMES
     sqlite3FileSuffix3(zFilename,pPager->zJournal);
     pPtr = (u8*)(pPager->zJournal + sqlite3Strlen30(pPager->zJournal)+1);
@@ -56458,8 +56541,8 @@ SQLITE_PRIVATE int sqlite3PagerOpen(
   /* Fill in Pager.zWal */
   if( nPathname>0 ){
     pPager->zWal = (char*)pPtr;
-    memcpy(pPtr, zPathname, nPathname);   pPtr += nPathname;
-    memcpy(pPtr, "-wal", 4);              pPtr += 4 + 1;
+    memcpy((char *)pPtr, zPathname, nPathname);   pPtr += nPathname;
+    memcpy((char *)pPtr, "-wal", 4);              pPtr += 4 + 1;
 #ifdef SQLITE_ENABLE_8_3_NAMES
     sqlite3FileSuffix3(zFilename, pPager->zWal);
     pPtr = (u8*)(pPager->zWal + sqlite3Strlen30(pPager->zWal)+1);
@@ -68753,6 +68836,7 @@ static int btreeCursor(
 
   /* Now that no other errors can occur, finish filling in the BtCursor
   ** variables and link the cursor into the BtShared list.  */
+  assert( EIGHT_BYTE_ALIGNMENT(pCur) );
   pCur->pgnoRoot = (Pgno)iTable;
   pCur->iPage = -1;
   pCur->pKeyInfo = pKeyInfo;
@@ -73073,6 +73157,7 @@ SQLITE_PRIVATE int sqlite3BtreeInsert(
         UnpackedRecord r;
         r.pKeyInfo = pCur->pKeyInfo;
         r.aMem = pX->aMem;
+        assert( EIGHT_BYTE_ALIGNMENT(r.aMem) );
         r.nField = pX->nMem;
         r.default_rc = 0;
         r.errCode = 0;
@@ -76980,6 +77065,7 @@ static sqlite3_value *valueNew(sqlite3 *db, struct Val
           assert( pRec->pKeyInfo->nAllField==nCol );
           assert( pRec->pKeyInfo->enc==ENC(db) );
           pRec->aMem = (Mem *)((u8*)pRec + ROUND8(sizeof(UnpackedRecord)));
+          assert( EIGHT_BYTE_ALIGNMENT(pRec->aMem) );
           for(i=0; i<nCol; i++){
             pRec->aMem[i].flags = MEM_Null;
             pRec->aMem[i].db = db;
@@ -77488,6 +77574,7 @@ SQLITE_PRIVATE void sqlite3Stat4ProbeFree(UnpackedReco
     int i;
     int nCol = pRec->pKeyInfo->nAllField;
     Mem *aMem = pRec->aMem;
+    assert( EIGHT_BYTE_ALIGNMENT(aMem) );
     sqlite3 *db = aMem[0].db;
     for(i=0; i<nCol; i++){
       sqlite3VdbeMemRelease(&aMem[i]);
@@ -79969,6 +80056,7 @@ SQLITE_PRIVATE void sqlite3VdbeMakeReady(
   */
   x.nNeeded = 0;
   p->aMem = allocSpace(&x, 0, nMem*sizeof(Mem));
+  assert( EIGHT_BYTE_ALIGNMENT(p->aMem) );
   p->aVar = allocSpace(&x, 0, nVar*sizeof(Mem));
   p->apArg = allocSpace(&x, 0, nArg*sizeof(Mem*));
   p->apCsr = allocSpace(&x, 0, nCursor*sizeof(VdbeCursor*));
@@ -79980,6 +80068,7 @@ SQLITE_PRIVATE void sqlite3VdbeMakeReady(
     x.nFree = x.nNeeded;
     if( !db->mallocFailed ){
       p->aMem = allocSpace(&x, p->aMem, nMem*sizeof(Mem));
+      assert( EIGHT_BYTE_ALIGNMENT(p->aMem) );
       p->aVar = allocSpace(&x, p->aVar, nVar*sizeof(Mem));
       p->apArg = allocSpace(&x, p->apArg, nArg*sizeof(Mem*));
       p->apCsr = allocSpace(&x, p->apCsr, nCursor*sizeof(VdbeCursor*));
@@ -80077,6 +80166,7 @@ SQLITE_PRIVATE int sqlite3VdbeFrameRestore(VdbeFrame *
   v->aOp = pFrame->aOp;
   v->nOp = pFrame->nOp;
   v->aMem = pFrame->aMem;
+  assert( EIGHT_BYTE_ALIGNMENT(v->aMem) );
   v->nMem = pFrame->nMem;
   v->apCsr = pFrame->apCsr;
   v->nCursor = pFrame->nCursor;
@@ -81544,6 +81634,7 @@ SQLITE_PRIVATE UnpackedRecord *sqlite3VdbeAllocUnpacke
   p = (UnpackedRecord *)sqlite3DbMallocRaw(pKeyInfo->db, nByte);
   if( !p ) return 0;
   p->aMem = (Mem*)&((char*)p)[ROUND8(sizeof(UnpackedRecord))];
+  assert( EIGHT_BYTE_ALIGNMENT(p->aMem) );
   assert( pKeyInfo->aSortFlags!=0 );
   p->pKeyInfo = pKeyInfo;
   p->nField = pKeyInfo->nKeyField + 1;
@@ -85309,9 +85400,10 @@ static VdbeCursor *allocateCursor(
 
   int nByte;
   VdbeCursor *pCx = 0;
-  nByte = 
-      ROUND8(sizeof(VdbeCursor)) + 2*sizeof(u32)*nField + 
-      (eCurType==CURTYPE_BTREE?sqlite3BtreeCursorSize():0);
+  size_t basicSize = ROUND8(ROUND8(sizeof(VdbeCursor)) + 2*sizeof(u32)*nField);
+  assert( EIGHT_BYTE_ALIGNMENT(SQLITE_INT_TO_PTR(basicSize)) );
+  nByte = ROUND8(basicSize + (eCurType==CURTYPE_BTREE?sqlite3BtreeCursorSize():0));
+  assert( EIGHT_BYTE_ALIGNMENT(SQLITE_INT_TO_PTR(nByte)) );
 
   assert( iCur>=0 && iCur<p->nCursor );
   if( p->apCsr[iCur] ){ /*OPTIMIZATION-IF-FALSE*/
@@ -85331,8 +85423,9 @@ static VdbeCursor *allocateCursor(
     pCx->nField = nField;
     pCx->aOffset = &pCx->aType[nField];
     if( eCurType==CURTYPE_BTREE ){
-      pCx->uc.pCursor = (BtCursor*)
-          &pMem->z[ROUND8(sizeof(VdbeCursor))+2*sizeof(u32)*nField];
+      assert( EIGHT_BYTE_ALIGNMENT(SQLITE_INT_TO_PTR(basicSize)) );
+      pCx->uc.pCursor = (BtCursor*)&pMem->z[basicSize];
+      assert( EIGHT_BYTE_ALIGNMENT(pCx->uc.pCursor) );
       sqlite3BtreeCursorZero(pCx->uc.pCursor);
     }
   }
@@ -85808,6 +85901,7 @@ SQLITE_PRIVATE int sqlite3VdbeExec(
   unsigned nProgressLimit;   /* Invoke xProgress() when nVmStep reaches this */
 #endif
   Mem *aMem = p->aMem;       /* Copy of p->aMem */
+  assert( EIGHT_BYTE_ALIGNMENT(aMem) );
   Mem *pIn1 = 0;             /* 1st input operand */
   Mem *pIn2 = 0;             /* 2nd input operand */
   Mem *pIn3 = 0;             /* 3rd input operand */
@@ -86222,6 +86316,7 @@ case OP_Halt: {
     }
     aOp = p->aOp;
     aMem = p->aMem;
+    assert( EIGHT_BYTE_ALIGNMENT(aMem) );
     pOp = &aOp[pcx];
     break;
   }
@@ -89432,6 +89527,7 @@ case OP_SeekGT: {       /* jump, in3, group */
     assert( oc!=OP_SeekLT || r.default_rc==+1 );
 
     r.aMem = &aMem[pOp->p3];
+    assert( EIGHT_BYTE_ALIGNMENT(r.aMem) );
 #ifdef SQLITE_DEBUG
     { int i; for(i=0; i<r.nField; i++) assert( memIsValid(&r.aMem[i]) ); }
 #endif
@@ -89653,6 +89749,7 @@ case OP_Found: {        /* jump, in3 */
     r.pKeyInfo = pC->pKeyInfo;
     r.nField = (u16)pOp->p4.i;
     r.aMem = pIn3;
+    assert( EIGHT_BYTE_ALIGNMENT(r.aMem) );
 #ifdef SQLITE_DEBUG
     for(ii=0; ii<r.nField; ii++){
       assert( memIsValid(&r.aMem[ii]) );
@@ -90750,6 +90847,7 @@ case OP_IdxInsert: {        /* in2 */
   x.nKey = pIn2->n;
   x.pKey = pIn2->z;
   x.aMem = aMem + pOp->p3;
+  assert( EIGHT_BYTE_ALIGNMENT(x.aMem) );
   x.nMem = (u16)pOp->p4.i;
   rc = sqlite3BtreeInsert(pC->uc.pCursor, &x,
        (pOp->p5 & (OPFLAG_APPEND|OPFLAG_SAVEPOSITION)), 
@@ -90819,6 +90917,7 @@ case OP_IdxDelete: {
   r.nField = (u16)pOp->p3;
   r.default_rc = 0;
   r.aMem = &aMem[pOp->p2];
+  assert( EIGHT_BYTE_ALIGNMENT(r.aMem) );
   rc = sqlite3BtreeMovetoUnpacked(pCrsr, &r, 0, 0, &res);
   if( rc ) goto abort_due_to_error;
   if( res==0 ){
@@ -91005,6 +91104,8 @@ case OP_IdxGE:  {       /* jump */
     r.default_rc = 0;
   }
   r.aMem = &aMem[pOp->p3];
+  assert( EIGHT_BYTE_ALIGNMENT(r.aMem) );
+
 #ifdef SQLITE_DEBUG
   {
     int i;
@@ -91574,6 +91675,8 @@ case OP_Program: {        /* jump */
     pFrame->nChildCsr = pProgram->nCsr;
     pFrame->pc = (int)(pOp - aOp);
     pFrame->aMem = p->aMem;
+    assert( EIGHT_BYTE_ALIGNMENT(pFrame->aMem) );
+
     pFrame->nMem = p->nMem;
     pFrame->apCsr = p->apCsr;
     pFrame->nCursor = p->nCursor;
@@ -91588,6 +91691,7 @@ case OP_Program: {        /* jump */
 #endif
 
     pEnd = &VdbeFrameMem(pFrame)[pFrame->nChildMem];
+    assert( EIGHT_BYTE_ALIGNMENT(aMem) );
     for(pMem=VdbeFrameMem(pFrame); pMem!=pEnd; pMem++){
       pMem->flags = MEM_Undefined;
       pMem->db = db;
@@ -91612,6 +91716,7 @@ case OP_Program: {        /* jump */
   p->nChange = 0;
   p->pFrame = pFrame;
   p->aMem = aMem = VdbeFrameMem(pFrame);
+  assert( EIGHT_BYTE_ALIGNMENT(aMem) );
   p->nMem = pFrame->nChildMem;
   p->nCursor = (u16)pFrame->nChildCsr;
   p->apCsr = (VdbeCursor **)&aMem[p->nMem];
@@ -95406,6 +95511,7 @@ static int vdbeSorterFlushPMA(VdbeSorter *pSorter){
       assert( pTask->list.aMemory==0 || pSorter->list.aMemory!=0 );
 
       aMem = pTask->list.aMemory;
+      assert( EIGHT_BYTE_ALIGNMENT(aMem) );
       pCtx = (void*)pTask;
       pSorter->iPrev = (u8)(pTask - pSorter->aTask);
       pTask->list = pSorter->list;
