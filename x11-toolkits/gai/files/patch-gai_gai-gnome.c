--- gai/gai-gnome.c.orig	Sat Aug 14 13:58:24 2004
+++ gai/gai-gnome.c	Sat Apr 23 17:06:12 2005
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
 
 
