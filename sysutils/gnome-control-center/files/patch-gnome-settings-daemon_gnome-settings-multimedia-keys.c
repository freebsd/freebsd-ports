--- gnome-settings-daemon/gnome-settings-multimedia-keys.c.orig	2007-09-18 05:32:43.000000000 -0400
+++ gnome-settings-daemon/gnome-settings-multimedia-keys.c	2007-10-28 13:45:28.000000000 -0400
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
 
@@ -708,7 +711,7 @@
 		do_mail_action (acme);
 		break;
 	case SLEEP_KEY:
-		do_sleep_action ("apm", "xset dpms force off");
+		do_sleep_action ("zzz", "xset dpms force off");
 		break;
 	case SCREENSAVER_KEY:
 		if ((cmd = g_find_program_in_path ("gnome-screensaver-command")))
