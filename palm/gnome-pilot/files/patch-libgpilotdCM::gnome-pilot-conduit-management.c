--- libgpilotdCM/gnome-pilot-conduit-management.c.orig	Thu Feb  6 03:35:48 2003
+++ libgpilotdCM/gnome-pilot-conduit-management.c	Wed Mar 12 23:12:10 2003
@@ -235,7 +235,7 @@
 			GList *iterator;
 
 			/* Do read of all .conduit files here */
-			conduit_files = self_get_conduit_file_names ("share/gnome-pilot/conduits", ".conduit");
+			conduit_files = self_get_conduit_file_names ("share/gnome/gnome-pilot/conduits", ".conduit");
  
 			LOCK_MY_HASHES;
 			conduitname_to_datastruct  = g_hash_table_new (g_str_hash,g_str_equal);
