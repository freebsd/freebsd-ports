
$FreeBSD$

--- src/encompass.c	2002/09/25 06:35:35	1.1
+++ src/encompass.c	2002/09/25 06:35:46
@@ -256,7 +256,7 @@
   data_mtx = g_mutex_new();
   gtk_mtx = g_mutex_new();
   gdk_rgb_init ();
-  sock_init();
+  ne_sock_init();
 	ne_debug_init (stdout, NE_DBG_SOCKET);
 
   gnome_vfs_init();
