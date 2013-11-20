--- src/netstat.c.orig	2012-04-13 06:33:27.000000000 -0500
+++ src/netstat.c	2012-04-13 06:34:30.000000000 -0500
@@ -114,7 +114,7 @@
 	g_return_val_if_fail (netinfo != NULL, NULL);
 	
 	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (netinfo->routing))) {
-#if defined (__OpenBSD__)
+#if defined (__OpenBSD__) || defined(__FreeBSD__)
 		if (netinfo_is_ipv6_enable ()) {
 			option = g_strdup ("-rn");
 		} else {
