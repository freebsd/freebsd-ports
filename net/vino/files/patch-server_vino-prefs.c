===================================================================
RCS file: /cvs/gnome/vino/server/vino-prefs.c,v
retrieving revision 1.2
retrieving revision 1.2.2.1
diff -u -r1.2 -r1.2.2.1
--- server/vino-prefs.c	2006/10/05 12:55:37	1.2
+++ server/vino-prefs.c	2006/10/10 10:42:38	1.2.2.1
@@ -306,7 +306,6 @@
 					       VINO_PREFS_VNC_PASSWORD,
 					       NULL);
   dprintf (PREFS, "Encoded password: %s\n", vino_vnc_password ? vino_vnc_password : "(null)");
-  g_free (vino_vnc_password);
 
   vino_listeners [i] =
     gconf_client_notify_add (vino_client,
