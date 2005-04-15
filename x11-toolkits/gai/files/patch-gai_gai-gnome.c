--- gai/gai-gnome.c.orig	Sat Aug 14 13:58:24 2004
+++ gai/gai-gnome.c	Fri Apr 15 22:52:09 2005
@@ -181,7 +181,7 @@
 static void gai_gnome_create_menu(void)
 {
     int i,ptr,j=0;
-    gnome_menu_verb = g_malloc0(sizeof(BonoboUIVerb)*GAI.menu_entries);
+    gnome_menu_verb = g_new0(BonoboUIVerb, GAI.menu_entries + 1);
 
     /* It will be freed anyway pretty soon */
     gnome_menu_xml = g_malloc0(81920);
@@ -225,6 +225,9 @@
 	ptr = strlen(gnome_menu_xml);
 
     }
+    gnome_menu_verb[j].cname = NULL;
+    gnome_menu_verb[j].cb = NULL;
+    gnome_menu_verb[j].user_data = NULL;
     sprintf(gnome_menu_xml+ptr,"</popup>\n");
 
 
@@ -345,8 +348,8 @@
 static int
 gai_gnome_expose(GtkWidget *widget, GdkEventExpose *event, gpointer d)
 {
-    static gboolean expose_lock = FALSE;
     GAI_ENTER;
+    static gboolean expose_lock = FALSE;
 
     if(expose_lock){
 	GAI_NOTE("Expose lock");
