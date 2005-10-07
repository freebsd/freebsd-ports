--- src/plugins/jabber/jabber_plugin.c.orig	Fri Oct  7 12:41:09 2005
+++ src/plugins/jabber/jabber_plugin.c	Fri Oct  7 12:44:32 2005
@@ -1458,6 +1458,8 @@
 
 void start_plugin()
 {
+	GGaduStatusPrototype *sp;
+
 	p = g_new0(GGaduProtocol, 1);
 	p->display_name = g_strdup("Jabber");
 	p->protocol_uri = g_strdup("xmpp:");
@@ -1505,7 +1507,7 @@
 	{
 		gint auto_status = (gint) ggadu_config_var_get(jabber_handler, "auto_status");
 		print_debug("jabber: autoconneting");
-		GGaduStatusPrototype *sp = ggadu_find_status_prototype(p, auto_status ? auto_status : JABBER_STATUS_AVAILABLE);
+		sp = ggadu_find_status_prototype(p, auto_status ? auto_status : JABBER_STATUS_AVAILABLE);
 		jabber_change_status(sp, FALSE);
 		GGaduStatusPrototype_free(sp);
 	}
