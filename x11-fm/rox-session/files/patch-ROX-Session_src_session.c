
$FreeBSD$

--- ROX-Session/src/session.c.orig	Sun Mar 23 21:11:38 2003
+++ ROX-Session/src/session.c	Sun Mar 23 21:12:38 2003
@@ -152,8 +152,8 @@
 	option_add_int(&mouse_accel_threshold, "accel_threshold", 10);
 	option_add_int(&mouse_accel_factor, "accel_factor", 20);
 
-	option_add_string(&halt_command, "halt_command", "halt");
-	option_add_string(&reboot_command, "reboot_command", "reboot");
+	option_add_string(&halt_command, "halt_command", "/sbin/shutdown -p now");
+	option_add_string(&reboot_command, "reboot_command", "/sbin/shutdown -r now");
 	option_add_string(&suspend_command, "suspend_command",
 			  "xset dpms force off");
 
