--- src/lib/libast/port/astcopy.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/port/astcopy.c
@@ -30,14 +30,10 @@
 #include <ast.h>
 #include <ast_mmap.h>
 
-#if _mmap_worthy > 1
-
 #include <ls.h>
 
 #define MAPSIZE		(1024*256)
 
-#endif
-
 #undef	BUFSIZ
 #define BUFSIZ		4096
 
