--- src/lib/libast/vmalloc/vmhdr.h.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/vmalloc/vmhdr.h
@@ -86,7 +86,7 @@
 #if defined(_WIN32)
 #define _mem_win32	1	/* use the VirtualAlloc interface	*/
 #endif
-#if !_mem_win32 && !_mem_sbrk && !_mem_mmap_anon && !_mem_mmap_zero
+#if !_mem_win32 && !_mem_sbrk && !_mem_mmap_anon
 #undef _std_malloc
 #define _std_malloc	1	/* use native malloc/free/realloc	*/
 #endif
@@ -160,11 +160,11 @@ extern void		_vmmessage _ARG_((const cha
 				    (ABORT() ? (abort(),0) : PAUSE() ? (pause(),0) : 0)) )
 #define COUNT(n)	((n) += 1)
 #define ACCOUNT(a,b)	((a) += (b))
-#define INITMEMORY(m,z)	((m) ? (memset((m), 'i', (z) > 2*ALIGN ? 2*ALIGN : (z)), 0) : 0 )
-#define SETBUSYMEM(m,z)	(memset(((char*)(m))+2*ALIGN, 'b', (z) <= 2*ALIGN ? 0 : ALIGN ) )
-#define CHKBUSYMEM(m,z)	(memcmp(((char*)(m))+2*ALIGN, "bbbbbbbb", (z) <= 2*ALIGN ? 0 : 8) == 0 ? 1 : 0 )
-#define SETFREEMEM(m,z)	(memset(((char*)(m))+2*ALIGN, 'f', (z) <= 2*ALIGN ? 0 : ALIGN ) )
-#define CHKFREEMEM(m,z)	(memcmp(((char*)(m))+2*ALIGN, "ffffffff", (z) <= 2*ALIGN ? 0 : 8) == 0 ? 1 : 0 )
+#define INITMEMORY(m,z)	((m) ? (memset((m), 'i', (z) > 2*MEM_ALIGN ? 2*MEM_ALIGN : (z)), 0) : 0 )
+#define SETBUSYMEM(m,z)	(memset(((char*)(m))+2*MEM_ALIGN, 'b', (z) <= 2*MEM_ALIGN ? 0 : MEM_ALIGN ) )
+#define CHKBUSYMEM(m,z)	(memcmp(((char*)(m))+2*MEM_ALIGN, "bbbbbbbb", (z) <= 2*MEM_ALIGN ? 0 : 8) == 0 ? 1 : 0 )
+#define SETFREEMEM(m,z)	(memset(((char*)(m))+2*MEM_ALIGN, 'f', (z) <= 2*MEM_ALIGN ? 0 : MEM_ALIGN ) )
+#define CHKFREEMEM(m,z)	(memcmp(((char*)(m))+2*MEM_ALIGN, "ffffffff", (z) <= 2*MEM_ALIGN ? 0 : 8) == 0 ? 1 : 0 )
 #define DEBUGDECL(_ty_,_ob_)	_ty_ _ob_;
 #else
 #define ABORT()		(0)
@@ -203,7 +203,7 @@ extern void		_vmmessage _ARG_((const cha
 #define BITS		(BUSY|PFREE|SMALL|MARK)
 #define ALIGNB		(BITS+1) /* to guarantee blksize == 0%(BITS+1)	*/
 
-/* ALIGN is chosen for three conditions:
+/* MEM_ALIGN is chosen for three conditions:
 ** 1. Able to address all primitive types.
 ** 2. A multiple of ALIGNB==(BITS+1) as discussed above.
 ** 3. Large enough to cover two pointers. Note that on some machines
@@ -238,9 +238,9 @@ struct _two_s
 	void*		two;
 };
 #define ALIGNA	(sizeof(struct _a_s) - sizeof(union _align_u))
-#undef	ALIGN	/* Blocks will be aligned on both ALIGNA & ALIGNB */
+#undef	MEM_ALIGN	/* Blocks will be aligned on both ALIGNA & ALIGNB */
 #define ALIGNAB	MULTIPLE(ALIGNA,ALIGNB)
-#define ALIGN	MULTIPLE(ALIGNAB, sizeof(struct _two_s))
+#define MEM_ALIGN	MULTIPLE(ALIGNAB, sizeof(struct _two_s))
 
 typedef union _word_u
 {	size_t		size;	/* to store a size_t	*/
@@ -252,7 +252,7 @@ struct _head_s /* a block header has two
 {	Word_t		one;
 	Word_t		two;
 };
-#define HEADSIZE	ROUND(sizeof(struct _head_s), ALIGN)
+#define HEADSIZE	ROUND(sizeof(struct _head_s), MEM_ALIGN)
 union _head_u
 {	Vmuchar_t	data[HEADSIZE];	/* to standardize size	*/
 	struct _head_s	head;
@@ -264,15 +264,15 @@ struct _body_s /* Note that self is actu
 	Block_t*	left;	/* left child in free tree	*/
 	Block_t**	self;	/* self pointer when free	*/
 };
-#define BODYSIZE	ROUND(sizeof(struct _body_s), ALIGN)
+#define BODYSIZE	ROUND(sizeof(struct _body_s), MEM_ALIGN)
 union _body_u
 {	Vmuchar_t	data[BODYSIZE];	/* to standardize size	*/
 	struct _body_s	body;
 };
 
 /* After all the songs and dances, we should now have:
-**	sizeof(Head_t)%ALIGN == 0
-**	sizeof(Body_t)%ALIGN == 0
+**	sizeof(Head_t)%MEM_ALIGN == 0
+**	sizeof(Body_t)%MEM_ALIGN == 0
 ** and	sizeof(Block_t) = sizeof(Head_t)+sizeof(Body_t)
 */
 struct _block_s
@@ -321,7 +321,7 @@ struct _block_s
 #define ENDB(sgb)	((Block_t*)((Vmuchar_t*)NEXT(sgb) - sizeof(Head_t)) )
 
 /* the start of allocatable memory in a segment */
-#define SEGDATA(sg)	((Vmuchar_t*)(sg) + ROUND(sizeof(Seg_t),ALIGN) )
+#define SEGDATA(sg)	((Vmuchar_t*)(sg) + ROUND(sizeof(Seg_t),MEM_ALIGN) )
 
 /* testing to see if "sg" is the root segment of a region */
 #define SEGROOT(sg)	((Vmuchar_t*)(sg)->vmdt >= (sg)->base && \
