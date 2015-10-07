--- src/netstat.c.orig	2012-01-03 10:38:09.000000000 +0100
+++ src/netstat.c	2015-08-28 16:21:17.101757000 +0200
@@ -114,7 +114,7 @@ netstat_get_active_option (Netinfo * net
 	g_return_val_if_fail (netinfo != NULL, NULL);
 	
 	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (netinfo->routing))) {
-#if defined (__OpenBSD__)
+#if defined (__OpenBSD__) || defined (__FreeBSD__)
 		if (netinfo_is_ipv6_enable ()) {
 			option = g_strdup ("-rn");
 		} else {
