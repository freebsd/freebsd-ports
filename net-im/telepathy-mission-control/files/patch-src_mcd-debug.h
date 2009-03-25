--- src/mcd-debug.h.orig	2009-03-24 23:45:58.000000000 -0400
+++ src/mcd-debug.h	2009-03-24 23:46:32.000000000 -0400
@@ -35,7 +35,7 @@ G_BEGIN_DECLS
 
 void mcd_debug_init ();
 
-inline gint mcd_debug_get_level ();
+gint mcd_debug_get_level ();
 
 void mcd_debug_ref (gpointer obj, const gchar *filename, gint linenum);
 void mcd_debug_unref (gpointer obj, const gchar *filename, gint linenum);
