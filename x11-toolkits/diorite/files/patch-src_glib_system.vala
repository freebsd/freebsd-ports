--- src/glib/system.vala.orig	2016-01-23 21:11:53 UTC
+++ src/glib/system.vala
@@ -61,7 +61,7 @@ namespace Diorite.System
 	}
 	
 	public async void make_directory_with_parents_async(
-		File directory, int io_priority=Priority.DEFAULT, Cancellable? cancellable = null) throws GLib.Error
+		File directory, int io_priority=GLib.Priority.DEFAULT, Cancellable? cancellable = null) throws GLib.Error
 	{
 		
 		SingleList<File> dirs = new SingleList<File>();
