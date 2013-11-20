--- embed/ephy-embed-prefs.c.orig	2011-04-26 00:08:02.000000000 +0200
+++ embed/ephy-embed-prefs.c	2011-04-28 08:59:55.000000000 +0200
@@ -482,6 +482,7 @@ ephy_embed_prefs_init (void)
   /* Hardcoded settings */
   g_object_set (webkit_settings,
                 "enable-default-context-menu", FALSE,
+                "enable-spell-checking", TRUE,
                 "enable-site-specific-quirks", TRUE,
                 "enable-page-cache", TRUE,
                 "enable-developer-extras", TRUE,
