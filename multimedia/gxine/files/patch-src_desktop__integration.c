--- src/desktop_integration.c.orig	2017-12-27 17:41:32 UTC
+++ src/desktop_integration.c
@@ -120,6 +120,9 @@ static void *get_func (const char *name)
 
 gboolean gxine_vfs_init (void)
 {
+#ifndef USE_INTEGRATION_WIZARD
+  return gnome_vfs_available = 0;
+#else
   void (*init_func) (void) = NULL;
 
   if (gnome_vfs_available != -1)
@@ -170,6 +173,7 @@ gboolean gxine_vfs_init (void)
 #endif
 
   return gnome_vfs_available = 1;
+#endif
 }
 
 /*
