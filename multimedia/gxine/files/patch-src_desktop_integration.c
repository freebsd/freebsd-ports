--- ./src/desktop_integration.c.orig	2008-05-23 22:42:20.000000000 +0400
+++ ./src/desktop_integration.c	2008-06-15 20:21:03.000000000 +0400
@@ -123,6 +123,9 @@
 
 gboolean gxine_vfs_init (void)
 {
+#ifndef USE_INTEGRATION_WIZARD
+  return gnome_vfs_available = 0;
+#else
   void (*init_func) (void) = NULL;
 
   if (gnome_vfs_available != -1)
@@ -173,6 +176,7 @@
 #endif
 
   return gnome_vfs_available = 1;
+#endif
 }
 
 /*
