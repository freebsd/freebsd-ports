
$FreeBSD$

--- ct1.h.orig	Sat Aug 31 01:07:06 2002
+++ ct1.h	Sat Aug 31 01:07:56 2002
@@ -224,8 +224,8 @@
 extern void check_fig2dev(void);
 
 #ifdef LIBUNDO
-extern int undo_free();
-extern int undo_malloc();
+extern void undo_free();
+extern void *undo_malloc();
 extern int undo_snapshot();
 #endif
 
