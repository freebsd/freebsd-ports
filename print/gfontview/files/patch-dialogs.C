--- dialogs.C.orig	Mon Mar 19 02:03:00 2001
+++ dialogs.C	Sun Aug 22 21:18:13 2004
@@ -1327,7 +1327,7 @@
   /* Entry field is DnD target */
   gtk_drag_dest_set(prtdiag->fileentry, GTK_DEST_DEFAULT_ALL,
 		    dnd_target_table, dnd_targets-1,
-		    (enum GdkDragAction)(GDK_ACTION_COPY | GDK_ACTION_MOVE)); 
+		    (GdkDragAction)(GDK_ACTION_COPY | GDK_ACTION_MOVE)); 
   gtk_signal_connect(GTK_OBJECT(prtdiag->fileentry), "drag_data_received",
 		     GTK_SIGNAL_FUNC(combo_drag_data_received), NULL);
 
