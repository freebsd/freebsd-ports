--- libslab/directory-tile.c.orig	Mon Mar 12 16:33:35 2007
+++ libslab/directory-tile.c	Mon Mar 12 16:35:48 2007
@@ -644,5 +644,5 @@ static void
 disown_spawned_child (gpointer user_data)
 {
 	setsid  ();
-	setpgrp ();
+	setpgrp (0, 0);
 }
