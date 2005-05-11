--- src.orig/gtkconv.c	Mon May  9 08:36:54 2005
+++ src/gtkconv.c	Mon May  9 08:37:32 2005
@@ -6369,8 +6369,8 @@
 	/* Conversations */
 	gaim_prefs_add_none("/gaim/gtk/conversations");
 	gaim_prefs_add_bool("/gaim/gtk/conversations/close_on_tabs", TRUE);
-	gaim_prefs_add_bool("/gaim/gtk/conversations/ctrl_enter_sends", FALSE);
-	gaim_prefs_add_bool("/gaim/gtk/conversations/enter_sends", TRUE);
+	gaim_prefs_add_bool("/gaim/gtk/conversations/ctrl_enter_sends", TRUE);
+	gaim_prefs_add_bool("/gaim/gtk/conversations/enter_sends", FALSE);
 	gaim_prefs_add_bool("/gaim/gtk/conversations/escape_closes", FALSE);
 	gaim_prefs_add_bool("/gaim/gtk/conversations/send_formatting", FALSE);
 	gaim_prefs_add_bool("/gaim/gtk/conversations/send_bold", FALSE);
