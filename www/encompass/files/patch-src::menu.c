
$FreeBSD$

--- src/menu.c	2002/09/25 06:35:35	1.1
+++ src/menu.c	2002/09/25 06:35:50
@@ -26,7 +26,7 @@
   gnome_config_pop_prefix();
   
   gnome_vfs_shutdown();
-  sock_exit();
+  ne_sock_exit();
 
   gtk_main_quit();
 }
