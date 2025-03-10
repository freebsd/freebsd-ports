--- extern.h.orig	2023-08-15 08:44:47 UTC
+++ extern.h
@@ -512,3 +512,5 @@
 /* layout.c */
 extern void  RemoveLayout __P((struct layout *));
 extern int   LayoutDumpCanvas __P((struct canvas *, char *));
+
+extern time_t SessionCreationTime __P((const char *));
