--- ./common/runtime/pub/hlxclib/malloc.h.orig	Fri Jul  9 03:45:31 2004
+++ ./common/runtime/pub/hlxclib/malloc.h	Fri Sep 10 21:56:56 2004
@@ -51,7 +51,7 @@
 #define HLXSYS_MALLOC_H
 
 #if !defined(_SYMBIAN) && !defined(_MACINTOSH) && !defined(_VXWORKS) \
-	&& !defined(_OPENWAVE) && !defined(_MAC_UNIX) && !defined(_FREEBSD5)
+	&& !defined(_OPENWAVE) && !defined(_MAC_UNIX) && !defined(_FREEBSD5) && !defined(_FREEBSD6) && !defined(_FREEBSD7)
 #include <malloc.h>
 #endif
 
