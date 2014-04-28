--- src/netstat.c.orig	Tue Jul  6 13:55:25 2004
+++ src/netstat.c	Fri Aug 20 15:55:40 2004
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
 
 		if (netinfo->stbar_text)
 			g_free (netinfo->stbar_text);
