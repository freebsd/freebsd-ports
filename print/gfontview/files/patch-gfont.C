--- gfont.C.orig	Tue Mar 20 06:04:14 2001
+++ gfont.C	Sun Aug 22 21:17:36 2004
@@ -1103,7 +1103,7 @@
   // Entry field of the combo box is DnD target
   gtk_drag_dest_set(entry, GTK_DEST_DEFAULT_ALL,
 		    dnd_target_table, dnd_targets-1,
-		    (enum GdkDragAction)(GDK_ACTION_COPY | GDK_ACTION_MOVE)); 
+		    (GdkDragAction)(GDK_ACTION_COPY | GDK_ACTION_MOVE)); 
   gtk_signal_connect(GTK_OBJECT(entry), "drag_data_received",
 		     GTK_SIGNAL_FUNC(combo_drag_data_received), NULL);
 
