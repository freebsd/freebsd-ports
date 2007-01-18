--- gtk/gtkrecentchoosermenu.c	2007/01/15 13:09:58	17157
+++ gtk/gtkrecentchoosermenu.c	2007/01/17 12:30:18	17172
@@ -941,6 +941,8 @@
       item = gtk_image_menu_item_new_with_label (text);
     }
 
+  g_free (text);
+
   label = GTK_BIN (item)->child;
   if (label)
     {
@@ -962,9 +964,6 @@
   		    G_CALLBACK (item_activate_cb),
   		    menu);
 
-out:
-  g_free (label);
-
   return item;
 }
 
