--- libgpilotdCM/gnome-pilot-conduit-management.c.orig	Tue Jun 19 09:47:42 2001
+++ libgpilotdCM/gnome-pilot-conduit-management.c	Sun Dec  2 02:55:26 2001
@@ -238,7 +238,7 @@
 			GList *iterator;
 
 			/* Do read of all .conduit files here */
-			conduit_files = get_conduit_file_names ("share/gnome-pilot/conduits", ".conduit");
+			conduit_files = get_conduit_file_names ("share/gnome/gnome-pilot/conduits", ".conduit");
  
 			LOCK_MY_HASHES;
 			conduitname_to_datastruct  = g_hash_table_new (g_str_hash,g_str_equal);
