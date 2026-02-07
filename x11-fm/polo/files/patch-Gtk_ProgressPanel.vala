--- Gtk/ProgressPanel.vala.orig	2018-08-12 04:41:58 UTC
+++ Gtk/ProgressPanel.vala
@@ -65,7 +65,7 @@ public abstract class ProgressPanel : Gtk.Box {
 
 	public signal void task_complete();
 
-	public ProgressPanel(FileViewPane _pane, Gee.ArrayList<FileItem>? _items, FileActionType _action){
+	protected ProgressPanel(FileViewPane _pane, Gee.ArrayList<FileItem>? _items, FileActionType _action){
 		//base(Gtk.Orientation.VERTICAL, 6); // issue with vala
 		Object(orientation: Gtk.Orientation.VERTICAL, spacing: 6); // work-around
 		margin = 6;
