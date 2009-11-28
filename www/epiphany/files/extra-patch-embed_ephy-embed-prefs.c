--- embed/ephy-embed-prefs.c.orig	2009-10-25 16:18:24.000000000 -0400
+++ embed/ephy-embed-prefs.c	2009-10-25 16:19:05.000000000 -0400
@@ -250,6 +250,9 @@ ephy_embed_prefs_init (void)
   /* Hardcoded settings */
   g_object_set (settings, "auto-shrink-images", FALSE, NULL);
 
+  /* Enable spell-check by default */
+  g_object_set (settings, "enable-spell-checking", TRUE, NULL);
+
   /* Connections */
   connections = g_malloc (sizeof (guint) * G_N_ELEMENTS (webkit_pref_entries));
 
