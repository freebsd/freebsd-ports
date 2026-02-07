--- src/lib/libast/vmalloc/vmdcsystem.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/vmalloc/vmdcsystem.c
@@ -66,18 +66,16 @@ static Vmemory_f	_Vmemoryf = 0;
 
 #if _std_malloc
 #undef	_mem_mmap_anon
-#undef	_mem_mmap_zero
 #undef	_mem_sbrk
 #undef	_mem_win32
 #endif
 
 #if _mem_win32
 #undef	_mem_mmap_anon
-#undef	_mem_mmap_zero
 #undef	_mem_sbrk
 #endif
 
-#if _mem_mmap_anon || _mem_mmap_zero /* may get space using mmap */
+#if _mem_mmap_anon /* may get space using mmap */
 #include		<sys/mman.h>
 #ifndef MAP_ANON
 #ifdef	MAP_ANONYMOUS
@@ -86,7 +84,7 @@ static Vmemory_f	_Vmemoryf = 0;
 #define MAP_ANON	0
 #endif /*MAP_ANONYMOUS*/
 #endif /*MAP_ANON*/
-#endif /*_mem_mmap_anon || _mem_mmap_zero*/
+#endif /*_mem_mmap_anon*/
 
 /*
  * hint at "transparent huge pages" (=largepages) if
@@ -259,73 +257,6 @@ static Void_t* mmapanonmem(Vmalloc_t* vm
 }
 #endif /* _mem_mmap_anon */
 
-#if _mem_mmap_zero /* get space by mmapping from /dev/zero */
-#include		<fcntl.h>
-#ifndef OPEN_MAX
-#define	OPEN_MAX	64
-#endif
-#define FD_PRIVATE	(3*OPEN_MAX/4)	/* private file descriptor	*/
-#define FD_NONE		(-2)		/* no mapping with file desc	*/
-
-/* this is called after an initial successful call of mmapzeromeminit() */
-static Void_t* mmapzeromem(Vmalloc_t* vm, Void_t* caddr, size_t csize, size_t nsize, Vmdisc_t* disc)
-{
-	Memdisc_t*	mmdc = (Memdisc_t*)disc;
-	off_t		offset;
-
-	GETMEMCHK(vm, caddr, csize, nsize, disc);
-	if(csize == 0)
-	{	nsize = ROUND(nsize, _Vmpagesize);
-		offset = asoaddoff(&mmdc->offset, nsize);
-		RESTARTMEM(caddr, mmap(NIL(Void_t*), nsize, PROT_READ|PROT_WRITE, MAP_PRIVATE, mmdc->fd, offset));
-		ADVISE(vm, caddr, nsize);
-		RETURN(vm, caddr, nsize);
-	}
-	else if(nsize == 0)
-	{	Vmuchar_t	*addr = (Vmuchar_t*)sbrk(0);
-		if(addr < (Vmuchar_t*)caddr ) /* in sbrk space */
-			return NIL(Void_t*);
-		(void)munmap(caddr, csize);
-		RETURN(vm, caddr, nsize);
-	}
-	else	return NIL(Void_t*);
-}
-
-/* if this call succeeds then mmapzeromem() is the implementation */
-static Void_t* mmapzeromeminit(Vmalloc_t* vm, Void_t* caddr, size_t csize, size_t nsize, Vmdisc_t* disc)
-{
-	Memdisc_t*	mmdc = (Memdisc_t*)disc;
-	int		fd;
-
-	GETMEMCHK(vm, caddr, csize, nsize, disc);
-	if(mmdc->fd != FD_INIT)
-		return NIL(Void_t*);
-	RESTARTSYS(fd, open("/dev/zero", O_RDONLY|O_CLOEXEC));
-	if(fd < 0)
-	{	mmdc->fd = FD_NONE;
-		return NIL(Void_t*);
-	}
-#if O_CLOEXEC == 0
-	else
-		SETCLOEXEC(fd);
-#endif
-	if(fd >= FD_PRIVATE || (mmdc->fd = fcntl(fd, F_DUPFD_CLOEXEC, FD_PRIVATE)) < 0)
-		mmdc->fd = fd;
-	else
-	{	close(fd);
-#if F_DUPFD_CLOEXEC == F_DUPFD
-		SETCLOEXEC(mmdc->fd);
-#endif
-	}
-	RESTARTMEM(caddr, mmapzeromem(vm, caddr, csize, nsize, disc));
-	if(!caddr)
-	{	close(mmdc->fd);
-		mmdc->fd = FD_NONE;
-	}
-	RETURN(vm, caddr, nsize);
-}
-#endif /* _mem_mmap_zero */
-
 #if _std_malloc /* using native malloc as a last resort */
 static Void_t* mallocmem(Vmalloc_t* vm, Void_t* caddr, size_t csize, size_t nsize, Vmdisc_t* disc)
 {
@@ -364,12 +295,6 @@ static Void_t* getmemory(Vmalloc_t* vm, 
 		return (Void_t*)addr;
 	}
 #endif
-#if _mem_mmap_zero
-	if((_Vmassert & VM_zero) && (addr = mmapzeromeminit(vm, caddr, csize, nsize, disc)))
-	{	GETMEMUSE(mmapzeromem, disc);
-		return (Void_t*)addr;
-	}
-#endif
 #if _mem_sbrk
 	if((_Vmassert & VM_break) && (addr = sbrkmem(vm, caddr, csize, nsize, disc)))
 	{	GETMEMUSE(sbrkmem, disc);
@@ -386,6 +311,7 @@ static Void_t* getmemory(Vmalloc_t* vm, 
 	if((_Vmassert & VM_native) && (addr = mallocmem(vm, caddr, csize, nsize, disc)))
 	{	GETMEMUSE(mallocmem, disc);
 		return (Void_t*)addr;
+	}
 #endif 
 	write(2, "vmalloc: panic: all memory allocation disciplines failed\n", 57);
 	abort();
