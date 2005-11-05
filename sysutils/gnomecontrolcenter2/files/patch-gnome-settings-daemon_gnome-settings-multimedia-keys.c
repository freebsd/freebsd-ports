--- gnome-settings-daemon/gnome-settings-multimedia-keys.c.orig	Wed Jul 27 13:52:13 2005
+++ gnome-settings-daemon/gnome-settings-multimedia-keys.c	Wed Jul 27 13:52:32 2005
@@ -828,7 +828,7 @@
 		do_mail_action (acme);
 		break;
 	case SLEEP_KEY:
-		do_sleep_action ("apm", "xset dpms force off");
+		do_sleep_action ("zzz", "xset dpms force off");
 		break;
 	case SCREENSAVER_KEY:
 		if ((cmd = g_find_program_in_path ("gnome-screensaver-command")))
