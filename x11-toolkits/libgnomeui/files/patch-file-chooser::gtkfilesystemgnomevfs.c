--- file-chooser/gtkfilesystemgnomevfs.c.orig	Sun Mar 20 20:58:22 2005
+++ file-chooser/gtkfilesystemgnomevfs.c	Sun Mar 20 20:59:03 2005
@@ -2536,13 +2536,20 @@
   GtkFileSystemGnomeVFS *system_vfs;
   GConfValue *value;
 
+  GDK_THREADS_ENTER();
+
   system_vfs = GTK_FILE_SYSTEM_GNOME_VFS (data);
 
   if (strcmp (gconf_entry_get_key (entry), BOOKMARKS_KEY) != 0)
-    return;
+    {
+      GDK_THREADS_LEAVE();
+      return;
+    }
 
   value = gconf_entry_get_value (entry);
   set_bookmarks_from_value (system_vfs, value, TRUE);
+
+  GDK_THREADS_LEAVE();
 }
 #endif
 
