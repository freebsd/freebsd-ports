--- src/netstat.c.orig	Sun Jul  4 17:57:03 2004
+++ src/netstat.c	Sun Jul  4 17:57:48 2004
@@ -108,12 +108,17 @@
 	g_return_val_if_fail (netinfo != NULL, NULL);
 	
 	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (netinfo->routing))) {
+#ifdef __FreeBSD__
+		/* XXX We only support ipv4 now */
+		option = g_strdup ("-rn -f inet");
+#else
 		/* Works for Solaris and Linux */
 		if (netinfo_is_ipv6_enable ()) {
 			option = g_strdup ("-rn -A inet -A inet6");
 		} else {
 			option = g_strdup ("-rn -A inet");
 		}
+#endif
 	}
 	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (netinfo->protocol))) {
 		/* Only works for Solaris */
