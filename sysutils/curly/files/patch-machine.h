$FreeBSD$

--- bin/curly/machine.h.orig	Wed Nov 13 08:08:13 2002
+++ bin/curly/machine.h	Wed Nov 13 08:08:48 2002
@@ -19,7 +19,7 @@
 #endif
 
 #if !defined(NEED_MALLOC_EXTERN)
-#define NEED_MALLOC_EXTERN	(!USE_MALLOC_H && !defined(NEXT2) && !defined(IRIX) && !defined(BSDI))
+#define NEED_MALLOC_EXTERN	(!USE_MALLOC_H && !defined(NEXT2) && !defined(IRIX) && !defined(BSDI) && !defined(FREEBSD))
 #endif
 
 #if !defined(USE_STDLIB)
