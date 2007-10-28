--- gnome-settings-daemon/gnome-settings-multimedia-keys.c.orig	2007-10-28 13:37:40.000000000 -0400
+++ gnome-settings-daemon/gnome-settings-multimedia-keys.c	2007-10-28 13:38:23.000000000 -0400
@@ -610,8 +610,11 @@
 	if ((command != NULL) && (strcmp (command, "") != 0))
 		execute (acme, command, FALSE, FALSE);
 	else
+#if __FreeBSD__
+		execute (acme, "cdcontrol eject", FALSE, FALSE);
+#else
 		execute (acme, "eject -T", FALSE, FALSE);
-
+#endif
 	g_free (command);
 }
 
