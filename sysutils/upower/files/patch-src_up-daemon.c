--- src/up-daemon.c.orig	2010-04-19 11:58:18.000000000 -0400
+++ src/up-daemon.c	2010-05-09 13:38:28.000000000 -0400
@@ -488,6 +488,8 @@ up_daemon_suspend_allowed (UpDaemon *dae
 		goto out;
 
 	ret = up_polkit_is_allowed (priv->polkit, subject, "org.freedesktop.upower.suspend", context);
+	if (!ret)
+		goto out;
 	dbus_g_method_return (context, ret);
 
 out:
@@ -575,6 +577,8 @@ up_daemon_hibernate_allowed (UpDaemon *d
 		goto out;
 
 	ret = up_polkit_is_allowed (priv->polkit, subject, "org.freedesktop.upower.hibernate", context);
+	if (!ret)
+		goto out;
 	dbus_g_method_return (context, ret);
 
 out:
