--- ./src/freebsd/up-backend.c.orig	2010-11-01 12:28:43.000000000 +0100
+++ ./src/freebsd/up-backend.c	2013-01-23 02:42:21.293236052 +0100
@@ -227,7 +227,7 @@
 	gchar *lid_state;
 
 	lid_state = up_get_string_sysctl (NULL, "hw.acpi.lid_switch_state");
-	if (lid_state && strcmp (lid_state, "NONE")) {
+	if (lid_state) {
 		up_daemon_set_lid_is_present (backend->priv->daemon, TRUE);
 	}
 	g_free (lid_state);