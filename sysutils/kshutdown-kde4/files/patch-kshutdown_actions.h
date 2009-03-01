--- actions.h.orig	2009-01-24 18:36:05.000000000 +1300
+++ kshutdown/actions.h	2009-01-24 18:35:58.000000000 +1300
@@ -28,7 +28,7 @@
 // TODO: 2.0: logout command for GNOME (gnome-session-save --kill?)
 	DEFAULT_LOGOUT_COMMAND(""),
 	DEFAULT_REBOOT_COMMAND("/sbin/reboot"),
-	DEFAULT_SHUT_DOWN_COMMAND("/sbin/poweroff");
+	DEFAULT_SHUT_DOWN_COMMAND("/sbin/halt -p");
 
 #define ks_actions Action::getInstance()
 
