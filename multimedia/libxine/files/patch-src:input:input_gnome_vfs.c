--- src/input/input_gnome_vfs.c.orig	Thu Aug 14 00:29:17 2003
+++ src/input/input_gnome_vfs.c	Thu Aug 14 00:29:22 2003
@@ -33,7 +33,7 @@
 
 #include <libgnomevfs/gnome-vfs.h>
 
-#define D(...)
+#define D(x...)
 /* #define D(...) g_message (__VA_ARGS__) */
 /* #define LOG */
 
