--- src/world.c.orig	Mon Dec 13 13:47:38 2004
+++ src/world.c	Fri Jan 14 18:00:30 2005
@@ -1308,7 +1308,6 @@
     g_free(sendLine);
 
     #ifdef HASRUBY
-      script_function *f;
       if ((f = script_find("on_login")) != NULL) {
         script_run(wld, f, NULL);
       }
@@ -1483,11 +1482,12 @@
   */
 void
 world_update(world * wld) {
+  gchar *logsDir, *tmpDir;
   interface_update_world(wld);
 
   // See if there is need to create a logs dir
-  gchar *logsDir = g_strconcat(wld->path, "/logs", NULL);
-  gchar *tmpDir = g_strconcat(wld->path, "/tmp", NULL);
+  logsDir = g_strconcat(wld->path, "/logs", NULL);
+  tmpDir = g_strconcat(wld->path, "/tmp", NULL);
 
   if (!g_file_test(logsDir, G_FILE_TEST_EXISTS)) {
     mkdir(logsDir, 0750);
@@ -1779,8 +1779,9 @@
   PangoContext *pc = gtk_widget_create_pango_context(wld->widgets.txtVwWorld);
 
   if (style->font_desc != NULL) {
+    PangoLayout *pl;
     pango_context_set_font_description(pc, style->font_desc);
-    PangoLayout *pl = pango_layout_new(pc);
+    pl = pango_layout_new(pc);
 
     pango_layout_set_text(pl, "G", 1);
     pango_layout_get_pixel_size(pl, &(wld->characterWidth), &(wld->characterHeight));
