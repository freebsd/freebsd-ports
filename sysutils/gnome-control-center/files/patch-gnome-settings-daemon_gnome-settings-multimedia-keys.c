--- gnome-settings-daemon/gnome-settings-multimedia-keys.c.orig	Thu Oct 14 15:44:21 2004
+++ gnome-settings-daemon/gnome-settings-multimedia-keys.c	Thu Oct 14 15:44:38 2004
@@ -813,7 +813,7 @@
 		do_mail_action (acme);
 		break;
 	case SLEEP_KEY:
-		do_sleep_action ("apm", "xset dpms force off");
+		do_sleep_action ("zzz", "xset dpms force off");
 		break;
 	case SCREENSAVER_KEY:
 		execute ("xscreensaver-command -lock", FALSE);
