--- src/gaim-rss-reader.c.orig	Sun Aug  8 17:44:40 2004
+++ src/gaim-rss-reader.c	Sun Aug  8 17:44:54 2004
@@ -255,10 +255,10 @@
 
 static void init_plugin(GaimPlugin *plugin)
 {
+    GList *sl = NULL;
     gaim_prefs_add_none("/plugins/gtk/gaim-rss-reader");
     gaim_prefs_add_int("/plugins/gtk/gaim-rss-reader/update_time", 60);
 
-    GList *sl = NULL;
     sl = g_list_append(sl, "Debian Planet;http://www.debianplanet.org/debianplanet/backend.php");
     sl = g_list_append(sl, "Mozillazine;http://www.mozillazine.org/contents.rdf");
     sl = g_list_append(sl, "Newsforge;http://www.newsforge.com/newsforge.rss");
