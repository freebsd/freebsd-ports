--- sfio/src/lib/sfio/sfsetbuf.c.orig	2008-02-11 09:54:38.000000000 +0100
+++ sfio/src/lib/sfio/sfsetbuf.c	2008-02-11 09:55:58.000000000 +0100
@@ -6,10 +6,6 @@
 
 #include	"sfhdr.h"
 
-#if _lib_memalign
-extern void *memalign _ARG_((size_t boundary, size_t size));
-#endif
-
 #if defined(__STDPP__directive) && defined(__STDPP__hide)
 __STDPP__directive pragma pp:nohide getpagesize
 #else
@@ -265,10 +261,6 @@
 		}
 		if(!buf)
 		{	/* do allocation */
-#if _lib_memalign
-			if(!(f->flags&SF_STRING) && _Sfpage && (size % _Sfpage) == 0)
-				buf = (Void_t*)memalign(_Sfpage,size);
-#endif
 			while(!buf && size > 0)
 			{	if((buf = (Void_t*)malloc(size)) )
 					break;
