--- src/callbacks.c.orig	2010-11-16 10:20:23 UTC
+++ src/callbacks.c
@@ -28,7 +28,7 @@ extern int delete;
 extern int context_id;
 extern int tview;
 
-struct menu_items bookmark_items[128];
+extern struct menu_items bookmark_items[128];
 extern int dont_select_damnit;
 extern int dont_update_entry;
 static struct tree *mibtree;
