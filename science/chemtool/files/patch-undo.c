
$FreeBSD$

--- undo.c.orig	Sat Mar  9 17:27:32 2002
+++ undo.c	Fri Aug 30 00:12:23 2002
@@ -61,7 +61,7 @@
 #define MAP_NEW_ANON_AT_FLAGS(pos, size, flags) \
             (mmap((pos), (size), \
 			      PROT_READ | PROT_WRITE | PROT_EXEC, \
-				  MAP_PRIVATE | MAP_ANONYMOUS | (flags), 0, 0))
+				  MAP_PRIVATE | MAP_ANON | (flags), -1, 0))
 #define MAP_NEW_ANON(size) MAP_NEW_ANON_AT_FLAGS(0, (size), 0)
 #define MAP_NEW_ANON_AT(pos, size) \
             MAP_NEW_ANON_AT_FLAGS((pos), (size), MAP_FIXED)
