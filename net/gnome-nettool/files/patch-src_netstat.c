--- src/netstat.c.orig	2022-04-06 01:52:01 UTC
+++ src/netstat.c
@@ -114,7 +114,7 @@ netstat_get_active_option (Netinfo * netinfo)
 	g_return_val_if_fail (netinfo != NULL, NULL);
 	
 	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (netinfo->routing))) {
-#if defined (__OpenBSD__)
+#if defined (__OpenBSD__) || defined (__FreeBSD__)
 		if (netinfo_is_ipv6_enable ()) {
 			option = g_strdup ("-rn");
 		} else {
