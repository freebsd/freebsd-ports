Right click context menu with wrong icon (bug #10652)

--- thunar/thunar-window.c.orig	2013-12-18 23:41:57 UTC
+++ thunar/thunar-window.c
@@ -345,8 +345,8 @@ struct _ThunarWindow
 static GtkActionEntry action_entries[] =
 {
   { "file-menu", NULL, N_ ("_File"), NULL, },
-  { "new-tab", NULL, N_ ("New _Tab"), "<control>T", N_ ("Open a new tab for the displayed location"), G_CALLBACK (thunar_window_action_open_new_tab), },
-  { "new-window", NULL, N_ ("New _Window"), "<control>N", N_ ("Open a new Thunar window for the displayed location"), G_CALLBACK (thunar_window_action_open_new_window), },
+  { "new-tab", "tab-new", N_ ("New _Tab"), "<control>T", N_ ("Open a new tab for the displayed location"), G_CALLBACK (thunar_window_action_open_new_tab), },
+  { "new-window", "window-new", N_ ("New _Window"), "<control>N", N_ ("Open a new Thunar window for the displayed location"), G_CALLBACK (thunar_window_action_open_new_window), },
   { "sendto-menu", NULL, N_ ("_Send To"), NULL, },
   { "empty-trash", NULL, N_ ("_Empty Trash"), NULL, N_ ("Delete all files and folders in the Trash"), G_CALLBACK (thunar_window_action_empty_trash), },
   { "detach-tab", NULL, N_ ("Detac_h Tab"), NULL, N_ ("Open current folder in a new window"), G_CALLBACK (thunar_window_action_detach_tab), },
